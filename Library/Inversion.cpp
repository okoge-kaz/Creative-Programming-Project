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
// 転倒数 Inversion のテンプレート
// verify https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D

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
    // 転倒数を求める場合

    int N; cin >> N;// size of vector(配列)
    vector<ll>A(N); for(ll &a:A) cin >> a;// 転倒数を求める対象の配列
    BIT<ll>bit(N+10);// +10しないとバグること多し
    vector<ll>B = A;// sortするのでコピーしないと順番が変化してしまう
    sort(B.begin(),B.end());
    B.erase(unique(B.begin(),B.end()),B.end());


    ll cnt = 0; // 転倒数 配列の長さが小さくても案外 intではオーバーフローする
    // 転倒数とは逆に i < j でA[i] <= A[j]となっているものの数
    ll res = 0;

    for(int i=0;i<N;i++){
        int id = lower_bound(B.begin(),B.end(),A[i]) -B.begin();
        cnt += (i) - bit.sum(id+1);// BITは1-indexed
        // cnt += i - bit.sum()のiは、これでよい
        res += bit.sum(id+1);
        bit.add(id+1,1);// 1-indexed
    }
    // bit.sum(id+1)は、id+1までの範囲で i<j && A[i] <= A[j]となっているものの個数
    
}