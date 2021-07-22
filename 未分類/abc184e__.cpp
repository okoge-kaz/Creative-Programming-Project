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

// 安易にdfsで書くと遷移は再帰関数で書けて楽だが、計算量の見積もりがしにくくなってしまう。
// 実際、今回のような最短経路を求める場合にはBFSなどで途中で打ち切りを行わないと、計算量がひどいことになってしまう
int main(){
    int h,w; cin >> h >> w;
    vector<string>A(h);
    for(string &e:A) cin >> e;
    // テレポートがあるがbfsで書ける
    vector cost(h,vector(w,INF));
    vector teleport(128,vector<pair<int,int>>{});
    // 128はアスキーコードが全部で128個であることに由来する
    int sx,sy,gx,gy;
    for(int i=0;i<h;i++)for(int j=0;j<w;j++){
        const char c = A[i][j];
        if(islower(c)){
            // 小文字であるこを確かめるのに使える
            teleport[c].push_back({i,j});
        }
        else if(c=='S') tie(sx,sy) = pair{j,i};// この書き方楽でよい
        else if(c=='G') tie(gx,gy) = pair{j,i};
    }
    cost[sy][sx] = 0;
    queue<pair<int,int>>que;
    que.push({sy,sx});

    while(!que.empty()){
        auto [y,x] = que.front(); que.pop();
        // 4方向への移動
        for(int i=0;i<4;i++){
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if(A[ny][nx]=='#') continue;
            if(chmin(cost[ny][nx],cost[y][x]+1)) que.push({ny,nx});
        }
        // テレポート
        if(islower(A[y][x])){
            // auto[ny,nx]:teleport[A[y][x]]とかくとTLEになる
            // t.clearとすることでteleportを2回以上同じ文字で使わなくて良いようにするためである。
            vector<pair<int,int>> &t = teleport[A[y][x]];
            for(auto[ny,nx]:t){
                // アスキー文字だがこのようにできてとても楽
                if(chmin(cost[ny][nx],cost[y][x]+1)) que.push({ny,nx});
            }
            t.clear();
            // この問題の肝は、一度使ったテレポートはもう一度使うことは最短経路においてはありえないということを用いている
        }
        if(cost[gy][gx]!=INF) break;
    }

    if(cost[gy][gx]==INF){ cout << -1 << endl; return 0; }
    cout << cost[gy][gx] << endl;
}