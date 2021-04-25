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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll H, W, T, M ,K;
vector<pair<ll,ll>>watch;
ll sx,sy,gx,gy;
ll dx[4] = {1,-1,0,0};
ll dy[4] = {0,0,1,-1};
void search(const vector<string> &G){
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(G[h][w]=='S') sx = w, sy = h;
            if(G[h][w]=='G') gx = w, gy = h;
            if(G[h][w]=='C') watch.push_back({h,w});// y,xの順
        }
    }
}
void dfs(vector<string> &G, vector<vector<bool>>&seen, ll y,ll x, bool time){
    seen[y][x] = true;
    for(int i=0;i<4;i++){
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= W || ny >= H)continue;
        if(seen[ny][nx]) continue;
        if(G[ny][nx]=='C' && !time){
            time = true;
            dfs(G,seen,ny,nx,time);
        }
        dfs(G,seen,ny,nx,time); 
    }
}
int main(){
    cin >> H >> W;
    cin >> T >> M >> K;
    vector<string>G(H);
    for(int i=0;i<H;i++){
        cin >> G[i];
    }
    vector<vector<bool>>seen(H,vector<bool>(W,false));
    bool time = false;
    dfs(G,seen,sy,sx,time);
}