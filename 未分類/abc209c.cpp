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
using lll = __int128_t;
int main(){
    int n; cin >> n;
    vector<ll>c(n); for(ll &e:c) cin >> e;
    // 一見難しく見えるがそうでもない

    // まずsortしても変化しないことを見抜くべし
    sort(c.begin(),c.end());
    mint ans = 1;
    for(int i=0;i<n;i++){
        ans *= max(0LL,c[i]-i);
        // 小さい方から決めていくと条件に合致することを見抜くべし
    }
    cout << ans.val() << endl;
}