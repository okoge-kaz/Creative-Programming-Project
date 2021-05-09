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
    ll N,K;
    cin >> N >> K;
    ll ans = N;
    for(int i=0;i<K;i++){
        if(ans % 200==0) ans /= 200;
        else{
            ans *= 1000;
            ans += 200;
        }
    }
    cout << ans << endl;
}