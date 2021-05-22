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
// https://atcoder.jp/contests/abc178/tasks/abc178_e
int main(){
    int N;
    cin >> N;
    vector<pair<int,int>>xy(N);
    for(int i=0;i<N;i++){
        int x, y; cin >> x >> y;
        xy[i] = pair(x,y);
    }
    // 競プロ典型にもあるけどマンハッタン距離のときは、式変形によって計算量削減が典型
    // https://atcoder.jp/contests/typical90/tasks/typical90_aj
    vector<ll>z(N),w(N);
    for(int i=0;i<N;i++) z[i] = (xy[i].first + xy[i].second);
    for(int i=0;i<N;i++) w[i] = (xy[i].first - xy[i].second);
    ll ans = 0;
    // ここで愚直に取得しようとするとO(N)
    ll min_w = INF; ll max_w = -INF;
    ll min_z = INF; ll max_z = -INF;
    for(int i=0;i<N;i++){
        chmin(min_w,w[i]); chmin(min_z,z[i]);
        chmax(max_w,w[i]); chmax(max_z,z[i]);
    }
    ans = max(abs(max_w - min_w), abs(max_z - min_z));
    cout << ans << endl;
}