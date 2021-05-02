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
int main(){
    ll N;
    cin >> N;
    vector<ll>A(N),B(N),C(N),D(N),E(N);
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];
    }
    ll ans = 0;
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            if(i==j) continue;
            ll aa = max(A[i],A[j]);
            ll bb = max(B[i],B[j]);
            ll cc = max(C[i],C[j]);
            ll dd = max(D[i],D[j]);
            ll ee = max(E[i],E[j]);
            for(ll k=0;k<N;k++){
                if(i==k||j==k) continue;
                chmax(aa,A[k]);
                chmax(bb,B[k]);
                chmax(cc,C[k]);
                chmax(dd,D[k]);
                chmax(ee,E[k]);
                ll tmp = min(aa,bb);
                chmin(tmp,cc);
                chmin(tmp,dd);
                chmin(tmp,ee);
                ans = max(ans,tmp);
            }
        }
    }
    cout << ans << endl;
}