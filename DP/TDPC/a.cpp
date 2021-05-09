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
    int N;
    cin >> N;
    vector<int>p(N);
    for(int i=0;i<N;i++) cin >> p[i];

    vector<vector<int>>dp(N+1,vector<int>(11000));
    dp[0][0] = 1;
    for(int i=0;i<N;i++){
        for(int v=0;v<=10000;v++){
            if(dp[i][v]==0) continue;
            dp[i+1][v] += dp[i][v];
            if(v+p[i]<=10000) dp[i+1][v+p[i]] += dp[i][v];
        }
    }
    ll cnt = 0;
    for(int i=0;i<=10000;i++) if(dp[N][i]) cnt++;
    cout << cnt << endl;
}