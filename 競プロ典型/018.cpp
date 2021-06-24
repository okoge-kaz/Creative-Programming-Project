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
ll T,L,X,Y;
ld query(int t){
    ld z = -(L/2.0) * (sin (PI/2.0 + 2*PI * (-t/(ld)T) ) ) + L/2.0;
    ld y = -(L/2.0) * (cos(2*PI*(-t)/(ld)T + PI/2.0));
    return atan2(z, sqrt((X*X + (Y-y)*(Y-y))));
}
int main(){
    cout << std::fixed << std::setprecision(15) ;
    cin >> T >> L >> X >> Y;
    ll Q; cin >> Q;
    for(int i=0;i<Q;i++){
        int E; cin >> E;
        cout << query(E)*(ld)180/PI << endl;;
    }
}