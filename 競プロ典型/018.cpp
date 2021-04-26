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
ll T, L, X, Y, Q;
ld get_z(ll t){
    ld z = L/(ld)2.0 - (L/(ld)2.0) * cos(((ld)t/T )* 2.0 * PI);
    return z;
}
ld get_y(ll t){
    ld y = - (L/(ld)2.0) * sin((ld)t/T * 2.0 * PI);
    return y;
}
int main(){
    cout << std::fixed << std::setprecision(20) ;
    // input
    cin >> T >> L >> X >> Y >> Q;
    vector<ll>E(Q);
    for(int i=0;i<Q;i++) cin >> E[i];
    
    for(int i=0;i<Q;i++){
        ld z = get_z(E[i]), y = get_y(E[i]);
        ld d = sqrt(X*X + (Y-y)*(Y-y));
        ld theta = atan2l(z,d);// atan2 は、(y,x)と引数をとるので注意
        cout << 180.0/PI *theta << endl;
    }
}