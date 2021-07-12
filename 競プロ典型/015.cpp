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

class Combination {
    private:
        const static int SIZE = 1000000;// O(N+α)かかるので
        vector<ll>fac, finv, inv;
    public:
        Combination(){
            fac.resize(SIZE); finv.resize(SIZE); inv.resize(SIZE);
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            for(int i=2;i<SIZE;i++){
                fac[i] = fac[i-1] * i % MOD;
                inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
                finv[i] = finv[i - 1] * inv[i] % MOD;
            }
        }
        ll com(int n, int k){
            if (n < k) return 0;
            if (n < 0 || k < 0) return 0;
            if(k > (n-k)) k = n-k;
            return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
        }
};

int main(){
    int N; cin >> N;
    // combination
    Combination comb;
    for(int k=1;k<=N;k++){
        mint ans = 0;
        for(int a=1;a<=(N-1)/k+1;a++){
            ans += comb.com(N-(k-1)*(a-1),a);
        }
        cout << ans.val() << endl;
    }
}