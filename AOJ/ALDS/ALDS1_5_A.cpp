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
    int n; cin >> n;
    vector<int>a(n); for(int &e:a) cin >> e;
    int m; cin >> m;
    vector<int>Q(m); for(int &e:Q) cin >> e;
    vector<vector<int>>dp(n+1,vector<int>(2100,-1));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=2000;j++){
            if(dp[i][j]!=-1){
                dp[i+1][j] = 1;
                if(j+a[i]<=2000) dp[i+1][j+a[i]] = 1;
            }
        }
    }
    for(int query=0;query<m;query++){
        if(dp[n][Q[query]]!=-1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}