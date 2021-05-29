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
int main(){
    int N,M;
    cin >> N >> M;
    vector<ll>H(N);
    for(int i=0;i<N;i++) cin >> H[i];
    sort(H.begin(),H.end());
    vector<ll>W(M);
    for(int i=0;i<M;i++) cin >> W[i];
    vector<ll>sum1((N+1)/2), sum2((N+1)/2);

    // 累積和であることは、わかったがうまく処理することができなかった。
    // 境界条件の処理等は、tatyamさんのとかから学びましょうね
    for(int i=0;i+1<N;i+=2) sum1[i/2+1] = sum1[i/2] + (H[i+1]-H[i]);
    for(int i=N-2;i>0;i-=2) sum2[i/2] = sum2[i/2+1] + (H[i+1]-H[i]);
    // 前からと後ろからで考えるのがよい
    ll ans = INF;
    for(int w:W){
        int x = lower_bound(H.begin(),H.end(),w) - H.begin();
        if(x & 1) x ^= 1;// 奇数の時は、偶数に変換
        chmin(ans,sum1[x/2] + sum2[x/2] + abs(H[x]-w));
    }
    cout << ans << endl;
}