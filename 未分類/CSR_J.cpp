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
    int N; cin >> N;
    vector<ll>A(N); for(ll &a:A) cin >> a;
    BIT<ll>bit(N+10);
    vector<ll>B = A;
    sort(B.begin(),B.end());
    // B.erase(unique(B.begin(),B.end()),B.end());
    ll res = 0;
    for(int i=0;i<N;i++){
        int id = lower_bound(B.begin(),B.end(),A[i]) - B.begin();
        // res += i - bit.sum(id+1)
        // i であることに注意
        // sum(id+1)まで、つまり自分より小さい範囲で i < j && A[j] <= A[i]となるものの個数が bit.sum(id+1)でわかるので、自分より一つ前のものまでの個数であるから i でよい
        res += (i) - bit.sum(id+1);
        bit.add(id+1,1);
    }
    cout << res << endl;
}