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
int main(){
    ll N,Q; cin >> N >> Q;
    vector<ll>x(Q),y(Q),z(Q),w(Q);
    for(int i=0;i<Q;i++){
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--; y[i]--; z[i]--;
    }
    mint ans = 1;
    for(ll d=0;d<60;d++){// d桁目について考える
        ll cnt = 0;
        for(ll bit=0;bit<(1LL<<N);bit++){
            vector<ll>A(N);
            for(int i=0;i<N;i++) if(bit & (1LL<<i)) A[i] = 1LL;
            bool flg = true;
            for(int q=0;q<Q;q++){
                ll W = (w[q] & (1LL<<d)) ?  1 : 0;
                if((A[x[q]] | A[y[q]] | A[z[q]]) != W ) flg = false;
            }
            if(flg) cnt++;
        }
        ans *= cnt;
    }
    cout << ans.val() << endl;
}