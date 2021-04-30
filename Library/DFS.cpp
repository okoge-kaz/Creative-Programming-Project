#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef long double ld;
const long long INF = 1LL << 60;
const ll mod = 998244353;
using Graph = vector<vector<ll>>;

// けんちょん本参考
// グラフGにおいて，頂点 s を始点とした探索を行う
void DFS(const Graph &G,int s){
    int N = (int)G.size();// グラフの頂点数

    // グラフ探索のためのデータ構造
    vector<bool> seen(N,false);// 全頂点を「未訪問」に初期化する
    stack<int> todo;// 深さ優先探索なので stack
    
    // 初期条件
    seen[s] = true;// s は探索済みにする
    todo.push(s);// todoはsのみを含む状態になる

    // todo が空になるまで探索を行う
    while(!todo.empty()){
        // todo から頂点を取り出す
        int v = todo.top();
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


// けんちょん本参考 再帰関数 による 深さ優先探索

vector<bool>seen;
void dfs(const Graph &G, int v){
    seen[v] = true;// v を探索済みにする

    // v から行ける各頂点 nv について
    for(auto nv: G[v]){
        if(seen[nv]) continue;// nv が探索済みなら探索しない
        dfs(G, nv); // 再帰的に
    }
}