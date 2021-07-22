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
    int n; cin >> n;
    vector<ll>a(n); for(ll &e:a) cin >> e;
    // dpを使うということに全く気づけなかった
    vector<vector<mint>>dp(n,vector<mint>(2));// 0: + , 1: -
    dp[0][0] = a[0];
    for(int i=0;i<n-1;i++){
        if(i==0){
            dp[i+1][0] = dp[i][0] + a[i+1];
            dp[i+1][1] = dp[i][0] - a[i+1];
            continue;
        }
        dp[i+1][0] = (dp[i][0] + 2*a[i+1] + dp[i][1]);
        dp[i+1][1] = dp[i][0] - a[i+1];
    }
    cout << (dp[n-1][0]+dp[n-1][1]).val() << endl;
}