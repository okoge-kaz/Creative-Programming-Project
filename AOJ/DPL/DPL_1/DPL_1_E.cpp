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
// 編集距離
int main(){
    string s1, s2; cin >> s1 >> s2;
    int n1 = (int)s1.size(); int n2 = (int)s2.size();
    vector<vector<ll>>dp(1100,vector<ll>(1100,INF));
    // dpは、dp[i][j] = s[i-1]からt[j-1]に変換する際の編集距離
    for(int i=0;i<=n1;i++) dp[i][0] = i;// 削除するコスト
    for(int i=0;i<=n2;i++) dp[0][i] = i;// 削除するコスト

    for(int i=1;i<=n1;i++){
        for(int j=1;j<=n2;j++){
            dp[i][j] = min({dp[i+1][j]+1,dp[i][j+1]+1,dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(s1[i-1]==s2[j-1]? 0 : 1)});
        }
    }
    cout << dp[n1][n2] << endl;
}