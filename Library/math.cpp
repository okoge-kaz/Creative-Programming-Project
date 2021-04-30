#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;

// 素因数分解した値をvectorで返す関数
vector<pair<ll,ll>>prime_factorize(ll N){
    // N を素因数分解する
    vector<pair<ll,ll>>res;
    for(ll a=2; a*a <= N;a++){
        if(N % a != 0) continue;
        ll ex = 0;// aの指数
        // 割れる限り割り続ける
        while(N % a==0){
            ++ex;
            N /= a;
        }
        res.push_back({a,ex});
    }
    // 最後に残った数について
    if(N != 1) res.push_back({N,1});// 1は素数でないので
    return res;
}

// combination の高速計算
// 詳細は https://drken1215.hatenablog.com/entry/2018/06/08/210000
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000) << endl;
}



// 繰り返し自乗法
long long modpow(long long a, long long n, long long m) {
    if (n == 0) return 1;
    long long half = modpow(a, n/2, m);
    long long res = half * half % m;
    if (n & 1) res = res * a % m;
    return res;
}
