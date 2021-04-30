#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// 格子構造上のDFS


// 格子状の幅優先探索のテンプレート(自作)

// グリッドのサイズ
ll H,W;
// 4方向へ進むパターン
pair<ll,ll> maze(ll i, pair<ll,ll> v){
    // i は、どこへ進むかを表す。
    pair<ll,ll>res;
    if(i==1){
        res.first = v.first + 1;
        res.second = v.second;
    }
    else if(i==2){
        res.first = v.first - 1;
        res.second = v.second;
    }
    else if(i==3){
        res.first = v.first;
        res.second = v.second + 1;
    }
    else{
        res.first = v.first;
        res.second = v.second - 1;
    }
    return res;
}
//
ll BFS(const vector<string> &G,ll sx,ll sy, ll gx,ll gy){
    // グラフ探索のためのデータ構造
    vector<vector<bool>> seen(H,vector<bool>(W,false));// 全頂点を「未訪問」に初期化する
    queue<pair<ll,ll>> todo;// 空の状態 幅優先探索なので queue
    vector<vector<ll>>dist(H,vector<ll>(W,-1));// 距離（最短経路を求める用）

    // 初期条件
    seen[sy][sx] = true;// s は探索済みにする
    dist[sy][sx] = 0;
    todo.push({sx,sy});// todoはsのみを含む状態になる

    // todo が空になるまで探索を行う
    while(!todo.empty()){
        // todo から頂点を取り出す
        pair v = todo.front();
        todo.pop();

        // v からたどれる頂点をすべて調べる
        for(int i=1;i<=4;i++){
            pair<ll,ll> nv = maze(i,v);
            ll nx = nv.first, ny = nv.second;

            if(nx>=W || nx < 0) continue;// 枠外
            if(ny>=H || ny < 0) continue;// 枠外
            if(G[ny][nx]=='#') continue;// 壁

            // すでに発見済みの頂点は訪問しない
            if(seen[ny][nx]) continue;
            // この処理をしないと，サイクルを含むグラフの場合，無限ループになる．

            // 新たな頂点 nv を探索済みとして todo に挿入
            seen[ny][nx] = true;
            dist[ny][nx] = dist[v.second][v.first] + 1;
            todo.push(nv);
        }
    }
    return dist[gy][gx];// 最短経路
}