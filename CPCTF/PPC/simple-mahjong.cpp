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
    ll N, M;
    cin >> N >> M;
    ll cnt = 0;
    // カードの選びかた
    ll exc = N - 3*M;
    vector<vector<ll>>dp(exc+1,vector<ll>(N+1));
    dp[0][0] = 1;
    for(int i=0;i<exc;i++){
        
    }
    //
    for(ll m=1;m<=M;m++){
        cnt *= m;
        cnt %= MOD;
    }
    cout << cnt << endl;
}