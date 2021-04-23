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
ll H,W,Q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
// グリットだからと何も考えずに幅優先探索してしまった O(V+E)より本文では 4 * 10^6一つのクエリごとにかかる
bool dfs(int ra, int rb, int ca, int cb, const vector<vector<bool>>&G){
    vector<vector<bool>>seen(H,vector<bool>(W));
    seen[ra][ca] = true;
    queue<pair<int,int>>que;
    que.push({ra,ca});
    while(!que.empty()){
        auto v = que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int ny = v.first + dy[i], nx = v.second + dx[i];
            if(ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if(!G[ny][nx]) continue;
            if(seen[ny][nx]) continue;//これ忘れやすい
            seen[ny][nx] = true;
            que.push({ny,nx}); 
        }
    }
    return seen[rb][cb];
}

// かつっぱさん参考
// Union-Find (depthあり)
struct UnionFind {
    vector<long long>par, siz, depth;
    // par: 各頂点の親頂点の番号を表します．自身が根の場合は-1とします．
    // siz: 各頂点の属する根付き木の頂点数を表します．
    // depth: 各頂点の深さを表します．（根の場合は depth=1 となる）

    // 初期化
    UnionFind(long long N) : par(N, -1LL), siz(N, 1LL), depth(N, 1LL) { }

    // 根を求める
    long long root(long long x){
        if(par[x] == -1) return x;// xが根の場合はxを返す
        else return par[x] = root(par[x]);// 経路圧縮
    }

    // x と y が同じグループに属するかどうか（根が一致するかどうか）
    bool issame(long long x,long long y){
        return root(x) == root(y);
    }

    // x を含むグループと yを含むグループとを併合する
    bool unite(long long x,long long y){
        // x, yをそれぞれ根まで移動する．
        x = root(x), y = root(y);

        // すでに同じグループのときは何もしない
        if(x == y) return false;// 統合(unite)していないのでfalseを返す

        // union by size( y 側のサイズが小さくなるようにする)
        if( depth[x] < depth[y]) swap(x,y);
        // 深さの更新
        if(depth[x] == depth[y]) depth[x]++;
        // y を x の子とする．
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    long long size(long long x){
        return siz[root(x)];
    }

    // xを含むグループの深さ（最深度）
    long long deep(long long x){
        return depth[root(x)];
    }
};

int main(){
    // input
    cin >> H >> W;
    cin >> Q;

    vector<vector<bool>>G(H,vector<bool>(W,false));// false = 白, true = 赤
    UnionFind uf((H+1)*(W+1));
    // query
    for(int i=0;i<Q;i++){
        ll q;
        cin >> q;
        if(q==1){
            ll r,c;
            cin >> r >> c;
            r--, c--;
            G[r][c] = true;
            if(r>0 && G[r-1][c]) uf.unite((r+1)*H+(c+1), (r)*H+c+1);
            if(c>0 && G[r][c-1]) uf.unite((r+1)*H+c+1,(r+1)*H+c);
            if(r+1 < H && G[r+1][c]) uf.unite((r+1)*H+c+1, (r+2)*H+c+1);
            if(c+1 < W && G[r][c+1]) uf.unite((r+1)*H+c+1,(r+1)*H+c+2);
        }
        else{
            ll ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--,rb--,ca--,cb--;
            //dfs(ra,rb,ca,cb,G) && (G[ra][ca] && G[rb][cb]) ? cout << "Yes" << endl : cout << "No" << endl;
            uf.issame((ra+1)*H+ca+1 , (rb+1)*H+cb+1) && (G[ra][ca] && G[rb][cb]) ? cout << "Yes" << endl : cout << "No" << endl;
        }
    }
}