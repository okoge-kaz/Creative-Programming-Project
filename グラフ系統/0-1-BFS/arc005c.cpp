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
// https://atcoder.jp/contests/arc005/tasks/arc005_3
int main(){
    int H,W;
    cin >> H >> W;
    vector<string> maze(H);
    for(int i=0;i<H;i++) cin >> maze[i];
    int sy,sx,gy,gx;
    for(int h=0;h<H;h++) for(int w=0;w<W;w++){
        if(maze[h][w]=='s') sy = h, sx = w;
        if(maze[h][w]=='g') gy = h, gx = w;
    }

    vector dist(H,vector (W,INF));
    dist[sy][sx] = 0LL;
    deque<pair<int,int>>que;
    // 0,1-BFS
    que.push_back({sy,sx});
    while(!que.empty()){
        auto [y,x] = que.front(); que.pop_front();
        for(int i=0;i<4;i++){
            int ny = y + dy[i]; int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if(maze[ny][nx]!='#'){
                if(chmin(dist[ny][nx],dist[y][x])){
                    que.push_front({ny,nx});
                }
            }
            else{
                if(chmin(dist[ny][nx],dist[y][x]+1)){
                    que.push_back({ny,nx});
                }
            }
        }
    }
    if(dist[gy][gx] > 2) cout << "NO" << endl;
    else cout << "YES" << endl;
}