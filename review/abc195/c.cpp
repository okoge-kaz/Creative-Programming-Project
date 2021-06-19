#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    // input
    ll N;
    cin >> N;
    // 出力用にans 
    ll ans = 0;
    ll limit = 1000;
    // 現在どこのカンマについて数え上げているのかを明示するためにlimit
    while(N >= limit){
        ans += (N - limit + 1);
        limit *= 1000;// 次のカンマにうつる
    }
    cout << ans << endl;
}