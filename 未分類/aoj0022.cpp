#include <bits/stdc++.h>
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
using lll = __int128_t;
int main(){
    int n;
    // 参考 http://theoryofprogramming.com/2016/10/21/dynamic-programming-kadanes-algorithm/
    while(cin >> n){
        if(n==0) break;
        vector<ll>a(n); for(ll &e:a) cin >> e;
        vector<ll>s(n);
        // mss maximum subsequence 最大部分和問題
        // 愚直にやるとO(N^2)
        ll ans = a[0];
        for(int i=0;i<n;i++){
            if(i==0) s[i] = a[i];
            else s[i] = max(s[i-1]+a[i],a[i]);
            chmax(ans,s[i]);
        }
        cout << ans << endl;
    }
}