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

// ワーシャルフロイド法 全点間最短距離
// 計算量 O(N^3)

// verified https://atcoder.jp/contests/abc208/tasks/abc208_d

int main(){
    int N,M; cin >> N >> M;
    // N: 頂点数, M: 辺数
    vector<vector<ll>>dist(N,vector<ll>(N,INF));
    for(int i=0;i<N;i++) dist[i][i] = 0LL;// 自分から自分への距離は0より
    // これ忘れやすいので注意

    // 辺のデータを受け取る
    for(int i=0;i<M;i++){
        int s,t; ll w; cin >> s >> t >> w;
        s--,t--;// 0-index
        chmin(dist[s][t],w);// 有向辺の場合
    }

    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                // 出発地点i, 終点j, 中継地点k

                // 負辺がある場合以下が必要
                // if(dist[i][k] == INF || dist[k][j] == INF) continue;

                chmin(dist[i][j],dist[i][k]+dist[k][j]);
                // ここで dist[i][j] != INFのときは k以下の点しか経由しないときの距離がわかる
            }
        }
    }
}