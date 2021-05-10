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
int main(){
    ll t,N;
    cin >> t >> N;
    ll b=ceil(N*100/t);
    ll x = b;
    while(true){
        if(ceil(x*t/100)>=N) break;
        x++;
    }
    cout << (ll)ceil(x*(1+t/100)) + N -1 << endl;
}