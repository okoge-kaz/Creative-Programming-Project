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
int main(){
    cout << std::fixed << std::setprecision(15) ;
    int N;
    cin >> N;
    vector<ld>p(N);
    for(int i=0;i<N;i++) cin >> p[i];

    vector<vector<ld>>dp(N,vector<ld>(N+1));// 表の枚数
    dp[0][1] = p[0];//表
    dp[0][0] = 1 - p[0];//裏
    for(int i=1;i<N;i++){
        for(int j=0;j<=N;j++){
            dp[i][j] +=  dp[i-1][j] * (1-p[i]);//表の枚数が変化しない
            if(j+1<=N) dp[i][j+1] += dp[i-1][j] * p[i];//一枚増える
        }
    }
    ld ans = 0;
    for(int i=N/2+1;i<=N;i++) ans += dp[N-1][i];
    cout << ans << endl;
}