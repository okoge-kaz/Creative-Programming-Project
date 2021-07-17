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
int H,W,D; vector<vector<int>>A;
int main(){
    // input 
    cin >> H >> W >> D;
    A.resize(H,vector<int>(W));
    for(int i=0;i<H;i++)for(int j=0;j<W;j++) cin >> A[i][j];
    // 前処理
    map<int,pair<int,int>>data;
    for(int i=0;i<H;i++)for(int j=0;j<W;j++) data[A[i][j]] = pair(i,j);
    vector<ll>sum(H*W+1);
    for(int i=1;i<=H*W;i++){
        if(i<=D) continue;
        sum[i] = sum[i-D] + abs(data[i].first - data[i-D].first) + abs(data[i].second - data[i-D].second);
    }
    // query
    int Q; cin >> Q;
    while(Q-->0){
        int L,R; cin >> L >> R;
        cout << sum[R]-sum[L] << endl;
    }
}