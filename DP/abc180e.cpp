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
    int N; cin >> N;
    vector<int>X(N),Y(N),Z(N);
    for(int i=0;i<N;i++){
        cin >> X[i] >> Y[i] >> Z[i];
    }
    // TSPに実質帰着できる。これは３角不等式から
    // 計算量は2^n n^2
    int N2 = 1<<N;
    vector<vector<int>>dp(N2,vector<int>(N,inf));
    vector<vector<int>>dist(N,vector<int>(N));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        int now = abs(X[i]-X[j]);
        now += abs(Y[i]-Y[j]);
        now += max(0,Z[i]-Z[j]);
        dist[i][j] = now;
    }
    for(int i=0;i<N;i++){
        if(i==0) continue;
        dp[1LL<<i][i] = dist[0][i];// 0からi頂点に移動する
    }
    // 集合演算の時は1LLとするの忘れずに
    for(int i=0;i<N2;i++) for(int j=0;j<N;j++){
        // if(i>>j & 1)記法の人が多いのは1LLにしないとオーバーフローする恐れがあるから
        if(i & (1LL<<j)){
            for(int k=0;k<N;k++){
                if(i & (1LL<<k)) continue;
                chmin(dp[i|(1LL<<k)][k],dp[i][j]+dist[j][k]);
                // k番目の頂点を訪れたようにして、かつ距離を更新
            }
        }
    }

    cout << dp[N2-1][0] << endl;// すべての頂点を訪問済みかつ＋頂点0にいる
    return 0;
}