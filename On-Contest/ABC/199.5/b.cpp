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
    cout << std::fixed << std::setprecision(15) ;
    int N,D,H;
    cin >> N >> D >> H;
    ld ans = 0;
    for(int i=0;i<N;i++){
        ld d, h;
        cin >> d >> h;
        ld tan_ = (ld)(H-h)/(D-d);
        ld tmp = H - D*tan_;
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}