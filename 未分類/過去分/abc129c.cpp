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
    int N, M;
    cin >> N >> M;
    vector<int>a(M);
    for(int i=0;i<M;i++) cin >> a[i];

    vector<ll>dp(N+1);
    for(int i=0;i<M;i++) dp[a[i]] = -1;
    dp[0] = 1LL;
    for(int i=0;i<N;i++){
        if(dp[i]==-1) continue;
        if((i+1) <= N){
            if(dp[i+1]!=-1){
                dp[i+1] += dp[i];
                dp[i+1] %= MOD;
            }
        }
        if((i+2) <= N){
            if(dp[i+2]!=-1){
                dp[i+2] += dp[i];
                dp[i+2] %= MOD;
            }
        }
    }
    
    cout << dp[N] % MOD << endl;
}