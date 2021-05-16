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
    int N, Q;
    cin >> N >> Q;
    vector seg(N+1,0);
    for(int i=0;i<Q;i++){
        int l, r;
        cin >> l >> r;
        l--,r--;// 0-index
        seg[l]++, seg[r+1]--;
    }
    for(int i=0;i<N;i++) seg[i+1] += seg[i];
    vector ans(N,0);
    for(int i=0;i<N;i++) if(seg[i] % 2 == 1) ans[i] = 1;
    for(auto s:ans) cout << s;
    cout << endl; 
}