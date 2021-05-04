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


// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
// x, y は、この関数を定義する前にテキトウに定義しておく必要あり
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long Mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
// a, mが互いに素でないと逆元は計算できない
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return Mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}

int main(){

}