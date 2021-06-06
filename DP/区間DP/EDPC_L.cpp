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
ll N; vector<ll>a; vector<vector<ll>>dp;
// min-max法典型問題
ll f(int l, int r){
    int diff = r-l;

    if(diff==0) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    // memo recursion

    if((N-diff)%2==0){
        dp[l][r] = max(f(l+1,r)+a[l],f(l,r-1)+a[r-1]);
    }
    else{
        // chminのときに-1で初期化したことがあだとなるので注意
        dp[l][r] = min(f(l+1,r)-a[l],f(l,r-1)-a[r-1]);
    }
    return dp[l][r];
}

int main(){
    cin >> N;
    a.resize(N); dp.resize(N+1,vector<ll>(N+1,-1LL));
    for(int i=0;i<N;i++) cin >> a[i];
    f(0,N);
    cout << dp[0][N] << endl;
}