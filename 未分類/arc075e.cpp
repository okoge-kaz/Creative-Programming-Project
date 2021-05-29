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
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;// ここで初期値を決定する
    vector<Abel> dat;
    
    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }
    
    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i){
            dat[i] = dat[i] + x;
        }
    }
    
    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }
    
    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }// 区間和
    
    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};
int main(){
    // https://drken1215.hatenablog.com/entry/2020/04/24/015400
    int N, K; cin >> N >> K;
    vector<ll>A(N); for(ll &a:A) cin >> a;
    // 平均K以上をすべてのaから-Kすることで考える
    for(ll &a:A) a -= K;
    vector<ll>sum(N+1); for(int i=0;i<N;i++) sum[i+1] = sum[i] + A[i];
    // 累積和をとることで部分列を高速に求めることができる
    // これで [l,r) の部分列はsum[r]-sum[l]となる
    // sum[r]-sum[l] >= 0 であれば、平均K以上となるので sum[r] >= sum[l]が条件
    // これで転倒数に帰着できた
    vector<ll> SS = sum;
    sort(SS.begin(), SS.end());
    SS.erase(unique(SS.begin(), SS.end()), SS.end());
    ll res = 0;
    BIT<ll>bit(N+10);
    for(int i=0;i<=N;i++){
        int id = lower_bound(SS.begin(),SS.end(),sum[i]) - SS.begin();
        res += bit.sum(id+1);//この+1は、1-indexedなので
        bit.add(id+1,1);
    }
    cout << res << endl;
}