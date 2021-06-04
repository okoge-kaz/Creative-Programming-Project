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
// 繰り返し自乗法
long long modpow(long long a, long long n, long long m) {
    if (n == 0) return 1;
    long long half = modpow(a, n/2, m);
    long long res = half * half % m;
    if (n & 1) res = res * a % m;
    return res;
}
int main(){
    ll m,n; cin >> m >> n;
    cout << modpow(m,n,MOD) << endl;
}