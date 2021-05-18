#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
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
int main(){
    ll K;
    cin >> K;
    if(K%9!=0) cout << 0 << endl;
    else{
        // ここでDPという発想がなかった
        vector<mint> dp(110000,0LL);
        dp[0] = 1;
        for(int i=1;i<=K;i++){
            int b = min(i,9);
            for(int j=1;j<=b;j++) dp[i] += dp[i-j];
        }
        cout << dp[K].val() << endl;
    }
}