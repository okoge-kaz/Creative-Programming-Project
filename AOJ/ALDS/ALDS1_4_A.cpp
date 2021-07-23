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
    int n; cin >> n;
    vector<int>s(n); for(int i=0;i<n;i++) cin >> s[i];
    map<int,int>data;
    for(int e:s) data[e]++;
    int q; cin >> q;
    vector<int>t(q); for(int &e:t) cin >> e;
    int ans = 0;
    for(int e:t){
        if(data[e]>0) ans++;
    }
    cout << ans << endl;
}