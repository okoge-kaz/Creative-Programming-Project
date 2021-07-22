#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;
using lll = __int128_t;
int main(){
    // このタイプの問題は頻出らしい
    int h,w; cin >> h >> w;
    vector<string>S(h);
    for(string &e:S) cin >> e;

    // dp + 累積和(segment treeでかけるはず...)
    vector dp(h,vector<mint>(w,0));
    // 以下の3つを考える
    vector dpx(h,vector<mint>(w,0));// 今(h,w)上にいる右方向に移動中のもの
    vector dpy(h,vector<mint>(w,0));// 今(h,w)上にいる下方向に移動中のもの
    vector dpxy(h,vector<mint>(w,0));// 今(h,w)上にいる右下（斜め）方向に移動中のもの

    dp[0][0] = 1;
    dpx[0][0] = 1;
    dpy[0][0] = 1;
    dpxy[0][0] = 1;

    // 移動中という概念をつくるとうまく実装できる
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(S[i][j]=='#') continue;
            if(i==0 && j==0) continue;
            if(i-1>=0) dpy[i][j] += dpy[i-1][j];
            if(j-1>=0) dpx[i][j] += dpx[i][j-1];
            if(i-1>=0 && j-1>=0) dpxy[i][j] += dpxy[i-1][j-1];
            // 現在(i,j)にいるがまだ飛翔中のものをdpに追加する
            dp[i][j] += dpx[i][j];
            dp[i][j] += dpy[i][j];
            dp[i][j] += dpxy[i][j];
            // dp[i][j]にあるものはどこかに移動しようと(i,j)上に飛翔できるので
            dpx[i][j] += dp[i][j];
            dpy[i][j] += dp[i][j];
            dpxy[i][j] += dp[i][j];
        }
    }
    cout << dp[h-1][w-1].val() << endl;
}