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
ll digit(ll x){
    ll res = 0;
    while(x) x/=10,res++;
    return res;
}
// xのn乗%modを計算
long long mod_pow(long long x, long long n, long long mod){
    long long res = 1;
    while(n > 0){
        if(n & 1) res = res*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return res;
}
// 教訓としては、powは使わずmod_powを使いましょうねということ
int main(){
    ll L,R; cin >> L >> R;
    mint ans = 0;
    if(digit(L)==digit(R)){
        ans = (R+L); ans *= (R-L+1); ans /= 2;
        ans *= digit(L);
    }
    else{
        for(ll d=digit(L);d<=digit(R);d++){
            if(d==digit(L)){
                mint tmp = mod_pow(10,d,MOD)-1;
                tmp += L;
                tmp *= mod_pow(10,d,MOD)-1 - L + 1;
                tmp /= 2; tmp *= d;
                ans += tmp;
                continue;
            }
            if(d==digit(R)){
                mint tmp = R;
                tmp += mod_pow(10,d-1,MOD);
                tmp *= R - mod_pow(10,d-1,MOD) + 1;
                tmp /= 2; tmp *= d;
                ans += tmp;
                continue;
            }
            mint tmp = mod_pow(10,d,MOD)-1;
            tmp += mod_pow(10,d-1,MOD);
            tmp *= mod_pow(10,d,MOD) -1 - mod_pow(10,d-1,MOD) + 1;
            tmp /= 2; tmp *= d;
            ans += tmp;
        }
    }
    cout << ans.val() << endl;
}