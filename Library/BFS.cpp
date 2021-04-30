#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;


using Graph = vector<vector<ll> >;
// けんちょん本参考 BFS 最短経路 距離
// 入力：グラフGと探索の始点 s
// 出力：s から各頂点への最短経路長を表す配列
vector<int>  BFS_dist(const Graph &G,int s){
    int N = (int)G.size();// グラフの頂点数

    // グラフ探索のためのデータ構造
    vector<int> dist(N,-1);// 全頂点を「未訪問」に初期化する 
    queue<int> todo;// 空の状態 幅優先探索なので queue
    
    // 初期条件
    dist[s] = 0;// s は探索済みにする 始点なので距離0
    todo.push(s);// todoはsのみを含む状態になる

    // todo が空になるまで探索を行う
    while(!todo.empty()){
        // todo から頂点を取り出す
        int v = todo.front();
        todo.pop();

        // v からたどれる頂点をすべて調べる
        for(int nv: G[v]){
            // すでに発見済みの頂点は訪問しない
            if(dist[nv]!=-1) continue;// 幅優先探索なので距離の近い順に更新される
            // この処理をしないと，サイクルを含むグラフの場合，無限ループになる．

            // 新たな頂点 nv を探索済みとして todo に挿入
            dist[nv] = dist[v] + 1;
            todo.push(nv);
        }
    }
    return dist;
}










// けんちょん本参考
// グラフGにおいて，頂点 s を始点とした探索を行う
void BFS(const Graph &G,int s){
    int N = (int)G.size();// グラフの頂点数

    // グラフ探索のためのデータ構造
    vector<bool> seen(N,false);// 全頂点を「未訪問」に初期化する
    queue<int> todo;// 空の状態 幅優先探索なので queue
    
    // 初期条件
    seen[s] = true;// s は探索済みにする
    todo.push(s);// todoはsのみを含む状態になる

    // todo が空になるまで探索を行う
    while(!todo.empty()){
        // todo から頂点を取り出す
        int v = todo.front();
        todo.pop();

        // v からたどれる頂点をすべて調べる
        for(int nv: G[v]){
            // すでに発見済みの頂点は訪問しない
            if(seen[nv]) continue;
            // この処理をしないと，サイクルを含むグラフの場合，無限ループになる．

            // 新たな頂点 nv を探索済みとして todo に挿入
            seen[nv] = true;
            todo.push(nv);
        }
    }
}