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
int H,W,N,M;
vector<vector<bool>>seen;
vector<vector<int>>used;
vector<vector<char>>maze;
void search1(int y,int x){
    // up
    if(y+1<H){
        if(maze[y+1][x]=='#') return;
        if(seen[y+1][x] && (used[y+1][x] & (1 << 1))) return;
        used[y+1][x] =  (used[y+1][x] | (1 << 1));
        seen[y+1][x] = true;
        search1(y+1,x);
    }
    return;
}
void search2(int y,int x){
    // down
    if(y-1>=0){
        if(maze[y-1][x]=='#') return;
        if(seen[y-1][x] && (used[y-1][x] & (1 << 2))) return;
        seen[y-1][x] = true;
        used[y-1][x] |= (1 << 2);
        search2(y-1,x);
    }
    return;
}
void search3(int y,int x){
    // right
    if(x+1<W){
        if(maze[y][x+1]=='#') return;
        if(seen[y][x+1] && (used[y][x+1] & (1 << 3))) return;
        used[y][x+1] |= (1 << 3);
        seen[y][x+1] = true;
        search3(y,x+1);
    }
    return;
}
void search4(int y,int x){
    // left
    if(x-1>=0){
        if(maze[y][x-1]=='#') return;
        if(seen[y][x-1] && (used[y][x-1] & (1 << 4))) return;
        seen[y][x-1] = true;
        used[y][x-1] |= (1 << 4);
        search4(y,x-1);
    }
    return;
}
int main(){
    cin >> H >> W >> N >> M;
    seen.resize(H,vector<bool>(W,false));
    used.resize(H,vector<int>(W,0));
    vector<pair<int,int>>yx(N);
    for(int i=0;i<N;i++){
        int h,w;
        cin >> h >> w;
        h--,w--;
        yx[i] = pair(h,w);
    }
    maze.resize(H,vector<char>(W));
    for(int h=0;h<H;h++) for(int w=0;w<W;w++) maze[h][w] = '.';
    for(int i=0;i<M;i++){
        int y,x;
        cin >> y >> x;
        y--,x--;
        maze[y][x] = '#';
    }
    for(int i=0;i<N;i++){
        auto [y,x] = yx[i];
        search1(y,x);
        search2(y,x);
        search3(y,x);
        search4(y,x);
    }
    for(int i=0;i<N;i++){
        auto [y,x] = yx[i]; 
        seen[y][x] = true;
    } 
    ll cnt = 0;
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) if(seen[i][j]) cnt++;
    cout << cnt << endl;
    // このままではTLE
    // メモ化は難しい
}