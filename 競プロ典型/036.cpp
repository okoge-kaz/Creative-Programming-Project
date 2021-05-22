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
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<ll>x(N),y(N);
    for(int i=0;i<N;i++) cin >> x[i] >> y[i];
    vector<ll>w(N), z(N);
    for(int i=0;i<N;i++){
        w[i] = (x[i] + y[i]);
        z[i] = (x[i] - y[i]);
    }
    ll max_w = -INF; ll min_w = INF;
    ll max_z = -INF; ll min_z = INF;
    for(int i=0;i<N;i++){
        chmin(min_w,w[i]); chmin(min_z,z[i]);
        chmax(max_w,w[i]); chmax(max_z,z[i]);
    }

    for(int q=0;q<Q;q++){
        int query; cin >> query;
        query--;
        ll res = 0;
        chmax(res,abs(max_w - w[query]));
        chmax(res,abs(w[query] - min_w));
        chmax(res,abs(max_z - z[query]));
        chmax(res,abs(z[query] - min_z));
        cout << res << endl;
    }
    
}