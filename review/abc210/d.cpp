#include <bits/stdc++.h>
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
using lll = __int128_t;
int main(){
    ll h,w,c; cin >> h >> w >> c;
    vector A(h,vector(w,0LL));
    for(int i=0;i<h;i++)for(int j=0;j<w;j++) cin >> A[i][j];
    // マンハッタン距離は項ごとにバラして考えるのがよい
    // .      .
    //  .   .      の２パターンがある
    // これについて気づけなかった
    ll ans = INF;
    // 始点についてのDP
    for(int rv=0;rv<2;rv++){
        // rv: reverse
        // 分かりにくいが、このreverseで右上に移動する場合も含むことができる
        vector dp(h,vector(w,INF));
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            chmin(dp[i][j],A[i][j]);
            // 左上から順々に決まっていくと考えて良い
            // 始点と終点を逆にすればよいので
            if(i-1>=0)chmin(dp[i][j],dp[i-1][j]+c);
            if(j-1>=0)chmin(dp[i][j],dp[i][j-1]+c);
        }
        // 終点に関するDP
        vector X(h,vector(w,INF));
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            if(i-1>=0) chmin(X[i][j],dp[i-1][j]+c+A[i][j]);
            if(j-1>=0) chmin(X[i][j],dp[i][j-1]+c+A[i][j]);
            // 終点における駅建設があるので
        }
        // 最小値を見つける
        for(int i=0;i<h;i++)for(int j=0;j<w;j++){
            chmin(ans,X[i][j]);
        }
        reverse(A.begin(),A.end());
        // test.cppで試すとわかるが一番外側の配列が反転される
    }
    cout << ans << endl;
}