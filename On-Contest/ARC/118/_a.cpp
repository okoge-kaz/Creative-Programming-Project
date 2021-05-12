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
ll t,N;
ll f(ll x){
    return floor((x * (100 + t))/(ld)100);
}
bool is_OK(ll x){
    if( f(x) - x >= N) return true;
    else return false;
}
int main(){
    cin >> t >> N;
    ll ok = (1LL << 50), ng = 1;
    // 二分探索において不用意に大きなINFとかしてしまうと、処理の途中で大きすぎて溢れてしまう
    // そうすると、どこでバグらせたか分からないので注意
    while(abs(ok - ng) > 1){
        // 税抜き価格の探索
        ll mid = (ok + ng)/2;
        if(is_OK(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok + N - 1 << endl;
}