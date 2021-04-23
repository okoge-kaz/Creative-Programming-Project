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
ll dp[110000][7];
int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    // 部分列
    // このように数を数える問題でかつ、部分列があまり大きくない時はDPが効果的
    string sub = "atcoder";
    if(S[0]==sub[0]){
        dp[0][0] = 1;
    }
    for(int i=1;i<N;i++){
        for(int j=0;j<7;j++){
            if(S[i]==sub[j]){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + 1;//新たに加わる
                    dp[i][j] %= MOD;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                dp[i][j] %= MOD;
            }
            else{
                dp[i][j] = dp[i-1][j];//そのままスライド
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[N-1][6] << endl;
}