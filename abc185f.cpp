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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

ll op(ll a,ll b){return (a ^ b);}//xorをとる処理
ll e(){ return 0LL;}// a xor 0 = aであることから0で初期化すればよい

int main(){
    ll N,Q;
    cin >> N >> Q;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    segtree<ll, op, e>seg(A);//配列を入れれば良い

    for(int q=0;q<Q;q++){
        ll T, X, Y;
        cin >> T >> X >> Y;
        if(T==1){
            X--;
            seg.set(X,Y^(seg.get(X)));//置き換え
        }
        else{
            X--,Y--;
            cout << seg.prod(X,Y+1) << "\n"; 
        }
    }
}