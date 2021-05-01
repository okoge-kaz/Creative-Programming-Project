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
// 3色塗り分け 
// 参考：ABC199 D https://atcoder.jp/contests/abc199/tasks/abc199_d

int N,M;
vector<vector<int>>G;
vector<bool>used;
vector<int>col;
vector<int>vs;// 連結成分ごとの頂点を格納
void dfs(int v){// このdfsは、連結成分に分ける用
    if(used[v]) return;
    used[v] = true;
    vs.push_back(v);
    for(int nv:G[v]) dfs(nv);//次の頂点へ
}
ll now;
void dfs2(int i){
    if(i==vs.size()){
        // すなわち、現在の連結成分のサイズと現在いる点の番号が等しい（これ以上点が存在しない）
        now++;//つまり一番端っこ
        return;
    }
    int v = vs[i];
    for(int c=0;c<3;c++){
        col[v] = c;
        bool ok = true;
        for(int u:G[v]){
            if(col[u]==c) ok = false;//隣接する頂点に同じ色のものがあった
        }
        if(!ok) continue;
        dfs2(i+1);
    }
    col[v] = -1;// col[v]が決定した色になっているとその上にある点の判定がおかしくなるので
}
int main(){
    cin >> N >> M;
    G.resize(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll ans = 1;
    // 初期化
    used.resize(N), col.resize(N);
    used.assign(N,false),col.assign(N,-1);
    for(int i=0;i<N;i++){
        //全頂点のついて探索
        if(used[i]) continue;//探索済みならスルー
        ans *= 3;//初めて探索する連結成分なので
        vs = vector<int>();//これで毎回vsを初期化できる
        dfs(i);//点iからたどりつけるすべての点へ
        // dfsの関数のなかでvsが呼び出される
        col[vs[0]] = 0;//新しい連結成分なので色は決めうち
        now = 0;
        dfs2(1);
        ans *= now;
    }
    cout << ans << endl;
    return 0;
}