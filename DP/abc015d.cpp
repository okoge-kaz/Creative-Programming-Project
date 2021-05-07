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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// 3次元dpを書くことができるぐらいの制約だったので
ll dp[51][11000][51];
int main(){
    ll W;
    cin >> W;
    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll>>wv(N);
    for(int i=0;i<N;i++) cin >> wv[i].first >> wv[i].second;

    for(int i=0;i<N;i++){
        //何番目をみているか
        for(ll w=0;w<=W;w++){
            //幅
            for(ll k=0;k<=K;k++){
                // 使用枚数
                
                //何もしない
                chmax(dp[i+1][w][k],dp[i][w][k]);
                // 更新
                if(w+wv[i].first <= W && k < K){
                    // 更新が行われるので k < K
                    chmax(dp[i+1][w+wv[i].first][k+1],dp[i][w][k] + wv[i].second);
                }
            }
        }
    }
    ll ans = 0;
    for(ll w=0;w<=W;w++){
        for(ll k=0;k<=K;k++){
            chmax(ans,dp[N][w][k]);
        }
    }
    cout << ans << endl; 
}