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
using mint = modint1000000007;
mint combination(ll n, ll k){
    mint ans = 1;
    for(ll i=0;i<k;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

int main(){
    ll n,a,b;
    cin >> n >> a >> b;
    mint ans = modpow(2LL,n,MOD);
    ans--;//0本はダメなので

    // https://drken1215.hatenablog.com/entry/2020/04/22/013400
    // 上にあるように、コンビネーション高速化でどうにかなりそうな気がするが、そういうわけではない
    // 逆元を用いた解法もあるようだが、nCkのkが小さく、かつnが大きいときは愚直なcombinationの方が早い

    ans -= combination(n,a);
    ans -= combination(n,b);
    cout << ans.val() << endl;// mint のときはval()で値をとる
}