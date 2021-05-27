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
// しっかりと覚えようね
int main(){
    ll n; cin >> n;
    vector<ll>a(n); for(int i=0;i<n;i++) cin >> a[i];

    // LIS Longest Incresing Sunsquence
    vector<ll>dp(n+1,INF);// 存在しない場合はINF
    for(int i=0;i<n;i++){
        *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];// a[i] < a[j]なので
        // a[i]を見つけてきたら、書き換えてしまう
    }
    cout << lower_bound(dp.begin(),dp.end(),INF) - dp.begin() << endl;
}