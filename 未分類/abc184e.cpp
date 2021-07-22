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
int h,w; vector<string>A;
vector<vector<ll>>dp;
void dfs(int x,int y, map<char,vector<pair<int,int>>> &data){
    ll cost = dp[y][x];
    // 4方向へ移動
    for(int i=0;i<4;i++){
        int nx = dx[i] + x; int ny = dy[i] + y;
        if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
        if(A[ny][nx]=='#')continue;
        if(chmin(dp[ny][nx],cost+1)){ dfs(nx,ny,data); }
    }
    //ワープ
    for(auto[ny,nx]:data[A[y][x]]){
        if(A[ny][nx]=='#')continue;
        if(chmin(dp[ny][nx],cost+1)){ dfs(nx,ny,data); }
    }
}
// dfs + chmin ではTLEしてしまう
// これは、dfsだと、あまりにも必要でない箇所まで入り込んでしまうから
int main(){
    cin >> h >> w;
    A.resize(h); for(string &e:A) cin >> e;
    dp.resize(h,vector<ll>(w,INF));
    int sx,sy; int gx,gy;
    map<char,vector<pair<int,int>>>data;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        if(A[i][j]=='S') { sx=j; sy=i; }
        if(A[i][j]=='G') { gx=j; gy=i; }
        if('a' <= A[i][j] && 'z' >= A[i][j]){
            data[A[i][j]].push_back({i,j});
        }
    }
    dp[sy][sx] = 0;
    dfs(sx,sy,data);
    if(dp[gy][gx]==INF){
        cout << -1 << endl;
        return 0;
    }
    cout << dp[gy][gx] << endl;
}