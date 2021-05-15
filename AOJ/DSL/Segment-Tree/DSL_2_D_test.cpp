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
// tatyamさんのを参考にした
template<class T> struct RUQ{
    int n, t = 0;
    vector<pair<int, T>> data;
    RUQ(int n, T a): n(n), data(n * 2, {0, a}) {}
    void query(int l, int r, T x){
        t++;
        l += n;
        r += n;
        while(l < r){
            if(l & 1) data[l++] = {t, x};
            if(r & 1) data[--r] = {t, x};
            l /= 2;
            r /= 2;
        }
    }
    T operator[](int a) const {
        a += n;
        pair ans = data[a];
        while(a >>= 1) if(ans < data[a]) ans = data[a];
        return ans.second;
    }
};
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    RUQ<int> seg(n, INT_MAX);
    while(q--){
        int t;
        cin >> t;
        if(t){
            int a;
            cin >> a;
            cout << seg[a] << '\n';
        }
        else{
            int l, r, x;
            cin >> l >> r >> x;
            seg.query(l, r + 1, x);
        }
    }
}