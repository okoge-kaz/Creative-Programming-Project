#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = (1LL << 31) - 1LL;
const int inf = (1 << 31);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class SegmentTree {
    private:
        ll n;
        vector<ll>node;
    public:
        SegmentTree(ll N){
            n = 1LL;
            while(n < N) n *= 2;
            node.resize(2*n -1,INF);
        }

        void update(int i, ll x){
            // １点更新
            i += (n-1);
            node[i] = x;
            while(i > 0){
                i = (i-1)/2;
                node[i] = min(node[2*i+1],node[2*i+2]);
            }
        }

        ll query(int a, int b, int k, int l, int r){
            // k は節点の番号、l,rはその節点が[l,r)に対応付いていることを表す
            // kは、[l,r)のなかのすべての条件を満たすもの
            if(r <= a || b <= l) return INF;
            if(a <= l && r <= b) return node[k];
            ll vl = query(a,b,2*k+1,l,(l+r)/2);
            ll vr = query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
};

int main(){
    // Range Minimum Query
    int n,q;
    cin >> n >> q;
    SegmentTree sg(n);
    ll N = 1;
    while(N < n) N*= 2;
    for(int i=0;i< q;i++){
        int com,l,r;
        cin >> com >> l >> r;
        if(com==0){
            sg.update(l,r);
        }
        else cout << sg.query(l,r+1,0,0,N) << endl;
        // [l,r)なので[0,n)とするべき
        // 上の引数については、デフォルト引数化したいところ
    }
}