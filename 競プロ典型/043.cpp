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
int H, W;
int sy, sx;
int gy, gx;
int main(){
    // 拡張BFS 0,1-BFS
    cin >> H >> W;
    cin >> sy >> sx;
    sy--,sx--;
    cin >> gy >> gx;
    gy--,gx--;
    vector<string>s(H);
    for(int i=0;i<H;i++) cin >> s[i];
    // 両端Queue, dequeを用いることが重要
    vector dist(H,vector(W, vector(4,INF)));// dist[i][j][k] (i,j)までのコスト、kどちらの方向を向いているか
    for(int i=0;i<4;i++) dist[sy][sx][i] = 0LL;
    deque<pair<int,int>>que;
    que.push_back(pair<int,int>(sy,sx));

    while(!que.empty()){
        auto [y,x] = que.front(); que.pop_front();
        for(int d=0;d<4;d++){
            if(y+dy[d]<0 || x+dx[d]<0 || y+dy[d]>=H || x+dx[d]>=W) continue;
            if(s[y+dy[d]][x+dx[d]]=='#') continue;
            int ny = y+dy[d]; int nx = x+dx[d];
            for(int i=0;i<4;i++){
                if(i==d){
                    if(chmin(dist[ny][nx][i],dist[y][x][i])) que.push_front({ny,nx});
                }
                else{
                    if(chmin(dist[ny][nx][d],dist[y][x][i] + 1)) que.push_back({ny,nx});
                }
            }
        }
    }
    cout << min({dist[gy][gx][0], dist[gy][gx][1], dist[gy][gx][2], dist[gy][gx][3]}) << endl;

}