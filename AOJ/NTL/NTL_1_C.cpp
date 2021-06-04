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
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
/* a と b の最小公倍数を求める */
long long LCM(long long a, long long b) {
    long long g = GCD(a, b);
    return a / g * b;
}
int main(){
    int n; cin >> n;
    vector<int>A(n); for(int &a:A) cin >> a;
    ll ans = 1LL;
    for(int i=0;i<n;i++) ans = LCM(ans,A[i]);
    cout << ans << endl;
}