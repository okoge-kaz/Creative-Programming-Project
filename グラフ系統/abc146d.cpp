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

using Edge = pair<int,int>;// 隣接頂点、辺番号
// 辺が関係するときはこのようにして管理することが求められる

int N;
vector<vector<Edge>>G;

void dfs(int v,int p,int pc, vector<int> &res){
    // v: 現在いる頂点, p: 親頂点, pc:(parent color)親頂点との間の辺の色
    int color = 1;
    if(color==pc) color++;//親頂点と被らないように
    for(auto e:G[v]){
        if(e.first==p) continue;// 逆流しない、これを書くので、木の場合はvector<bool>seen, usedのような配列を書く必要がない
        res[e.second] = color;
        dfs(e.first, v, color,res);
        ++color;//次の頂点にいくのでインクリメント
        if(color==pc) ++color;
    }
}
int main(){
    cin >> N;
    G.resize(N);
    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    // 一般のグラフの場合は最大次数＋１ですべてを塗り分けることが可能だが、木の場合は最大次数で塗り分け可能
    int max_color = 0;
    for(int i=0;i<N;i++) chmax(max_color,(int)G[i].size());// .size()を使うときはちゃんと型変換を(int)とすること
    // 辺の数は木であれば必ず、頂点数−１となる
    cout << max_color << endl;
    vector<int>res(N-1,-1);
    dfs(0,-1,-1,res);
    for(int v:res) cout << v << endl;
}