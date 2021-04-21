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
int main(){
    int N;
    cin >> N;
    vector<vector<int>>G(N);// 隣接グラフ構造
    for(int i=0;i<N-1;i++){
        int A, B;
        cin >> A >> B;
        A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    // 木の直径を求めるアルゴリズムは、典型問題らしい
    // alogrithm logic にも典型問題として掲載されている https://algo-logic.info/tree-diameter/
    vector<int>dist(N,-1);
    queue<int>que;
    que.push(0);
    dist[0] = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int nv:G[v]){
            if(dist[nv]!=-1) continue;
            que.push(nv);
            dist[nv] = dist[v] + 1;
        }
    }
    int ans = 0;
    int u = -1;//木の直径となる端点のうちの片方
    for(int i=0;i<N;i++){
        if(chmax(ans,dist[i])) u = i;
    }
    //
    vector<int>dist2(N,-1);
    queue<int>qu;
    qu.push(u);
    dist2[u] = 0;
    int res = 0;
    while(!qu.empty()){
        int v = qu.front();
        qu.pop();
        for(int nv:G[v]){
            if(dist2[nv]!=-1) continue;
            qu.push(nv);
            dist2[nv] = dist2[v] + 1;
        }
    }
    //for(int i=0;i<N;i++) cout << dist2[i] << endl;
    for(int i=0;i<N;i++) chmax(res,dist2[i]);
    cout << ++res << endl;
}