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
ll N,S;
vector<ll>a;
int main(){
    cin >> N >> S;
    a.resize(N);
    for(int i=0;i<N;i++) cin >> a[i];
    ll r = 0;
    ll ans = INF;
    ll crr = 0;
    // [l,r)閉区間になってしまっている
    for(int l=0;l<N;l++){
        while(r < N && crr < S){
            crr += a[r++];
            // 足してからr++
        }
        if(crr < S) break;

        chmin(ans,(r-l));
        if(r==l) r++;
        crr -= a[l];
    }
    if(ans == INF) ans = 0;
    cout << ans << "\n";
}