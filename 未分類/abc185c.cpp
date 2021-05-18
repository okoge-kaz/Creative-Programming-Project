#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int inf = (1 << 30);
const ll mod = 998244353;
const ll MOD = 1000000007;
const ld PI = acos(-1.0L);
int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll combination(ll n, ll k){
    // combinationをするときは、kの方の値が小さくなることが確約されている方を使うように
    ll ans = 1;
    for(ll i=0;i<k;i++){
        ans *= (n-i);
        ans /= (i+1);
    }
    return ans;
}

int main(){
    ll L;
    cin >> L;
    ll ans = 0;
    ll l = L -12;
    ans += combination(l+11,11);
    cout << ans << endl;
}