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
using lll = __int128_t;
int main(){
    int n; ll k; cin >> n >> k;
    vector<ll>a(n); for(ll &e:a) cin >> e;
    vector<ll>cnt(n,k/n);
    k %= n;
    vector<pair<ll,int>>b(n);
    for(int i=0;i<n;i++) b[i] = pair(a[i],i);
    sort(b.begin(),b.end());
    for(int i=0;i<k;i++){
        cnt[b[i].second]++;
    }
    
    for(ll e:cnt) cout << e << endl;
}