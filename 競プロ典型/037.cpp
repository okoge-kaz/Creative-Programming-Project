#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T>
class RangeMaxQuery {
    private:
        ll SEG_LEN; vector<T>node;
    public:
        RangeMaxQuery(ll n){
            SEG_LEN = 1LL;
            while(SEG_LEN < n) SEG_LEN *= 2;
            node.resize(2*SEG_LEN,-(1LL << 31));
            // Range Max Queryより
        }
        // RMQと言っても一点更新がupdateなのか加算なのかは不明なため
        void update(ll index, T value){
            index += (SEG_LEN);
            node[index] = value;
            while(index>0){
                index /= 2;
                node[index] = max(node[2*index],node[index*2+1]);
            }
        }
        void add(ll index, T value){
            index += (SEG_LEN);
            node[index] += value;
            while(index>0){
                index /= 2;
                node[index] = min(node[2*index],node[index*2+1]);
            }
        }
        T query(ll l, ll r){
            // [l,r)なのでr++が呼び出す側では必要
            l += SEG_LEN; r += SEG_LEN;
            ll res = -(1LL << 31);
            while(l<r){
                // [l,r)区間
                if(l%2==1){
                    chmax(res,node[l]);
                    l++;
                }
                l /= 2;
                if(r%2==1){
                    chmax(res,node[r-1]);
                    r--;
                }
                r /= 2;
            }
            return res;
        }
};
// DPをセグメント木で高速化するタイプの問題らしい
int main(){
    ll W,N; cin >> W >> N;
    vector<ll>L(N), R(N), V(N);
    for(int i=0;i<N;i++) cin >> L[i] >> R[i] >> V[i];

    vector<vector<ll>>dp(N+1,vector<ll>(W+1,-1));
    dp[0][0] = 0;

    for(int i=0;i<N;i++){
        // セグメント木を用意
        RangeMaxQuery<ll>seg(W);
        for(int j=0;j<=W;j++) seg.update(j,dp[i][j]);

        for(int j=0;j<=W;j++){
            if(dp[i][j]==-1) continue;
            chmax(dp[i+1][j],dp[i][j]);//何も選ばない
        }

        for(int j=0;j<=W;j++){
            if(j<L[i]) continue;
            int cl = max(0LL,j-R[i]); int cr = max(0LL,j-L[i]+1);
            // j-L[i]+1しないとcontinueになってしまう
            if(cl==cr) continue;// segment木は1-indexedなのでそのまま使える
            ll val = seg.query(cl,cr);// 1-indexかつ[l,r)
            if(val!=-1) chmax(dp[i+1][j],val+V[i]);
        }
    }
    cout << dp[N][W] << endl;
}