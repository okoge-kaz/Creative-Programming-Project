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
    int q; cin >> q;
    for(int i=0;i<q;i++){
        string s,t; cin >> s >> t;
        vector<vector<ll>>dp(1100,vector<ll>(1100,0LL));
        int n = (int)s.size(); int m = (int)t.size();
        for(int j=0;j<n;j++) for(int k=0;k<m;k++){
            if(s[j]==t[k]){
                dp[j+1][k+1] = max({dp[j+1][k+1],dp[j][k]+1});
                // ここでdp[j+1][k+1] = dp[j][k+1] + 1としてはいけないのは、すでにk+1番目が共通文字として使われている可能性があるから
            }
            dp[j+1][k+1] = max({dp[j+1][k+1],dp[j][k+1],dp[j+1][k],dp[j][k]});
            // このタイプの問題は紛らわしいので、全て書いておけば良い
        }
        cout << dp[n][m] << endl;
    }
}