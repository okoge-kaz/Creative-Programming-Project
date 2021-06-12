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
int main(){
    // 個数制限ありナップザック
    // 個数制限付き部分和問題と違ってスライド最小値の技法を用いる必要がある。
    ll N,W; cin >> N >> W;
    vector<ll>v(N), w(N), m(N);
    for(int i=0;i<N;i++) cin >> v[i] >> w[i] >> m[i];
    vector<vector<ll>>dp(N+1,vector<ll>())
}