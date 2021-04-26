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
ll N,M;
vector<vector<ll>>G;// 普通のグラフ
vector<vector<ll>>rG;//辺の向きを逆にしたグラフ

vector<ll>vs;//帰りがけ順の並び
vector<bool>seen;// G のときに使う
vector<bool>used;// rG のときに使う
vector<ll>cmp;//属する強連結成分のトポロジカル順序

// 帰りがけdfs
void dfs(ll v){
    seen[v] = true;
    for(ll nv:G[v]){
        if(!seen[nv]) dfs(nv);//探索済みでないなら探索
    }
    vs.push_back(v);//帰りがけ
}

// 逆向きにしてdfs
void rdfs(ll v, ll k){
    // k は、属する強連結成分の番号を管理するため
    used[v] = true;
    cmp[v] = k;//属する強連結成分を表す
    for(ll nv:rG[v]){
        if(!used[nv]){
            rdfs(nv,k);
        }
    }
}
ll scc(){
    // Strongly Connected Component

    // 最初の帰りがけDFSで使う探索済みかどうかを管理する配列の初期化
    seen.resize(N);
    seen.assign(N,false);//何もしなくてもfalseで初期化されるがあえて明示的に
    // DFS
    for(ll v=0;v<N;v++){// Nは頂点数
        if(!seen[v]) dfs(v);
    }

    // rG 有向グラフを反対にした際に探索済みかどうかを管理する配列の初期化
    used.resize(N);
    used.assign(N,false);
    // DFS
    ll k = 0;
    for(ll i=N-1;i>=0;i--){// 帰りがけしたものを逆にたどるので
        if(!used[vs[i]]) rdfs(vs[i], k++);// k++なので、呼び出し後に足される
    }

    return k;
}

int main(){
    // input
    cin >> N >> M;
    // assign and resize
    G.resize(N);
    rG.resize(N);
    cmp.resize(N);
    //
    set<pair<ll,ll>>ab;
    for(int i=0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        ab.insert({a,b});
    }
    for(auto [a,b]:ab){
        //cout << a+1 << " " << b+1 << endl;
        G[a].push_back(b);// 有向グラフなので
        rG[b].push_back(a);// 辺の向きを逆にしたグラフについて
    }

    // 愚直にすると、O(N(N+M))
    scc();
    ll ans = 0;
    map<ll,ll>scc_vs;
    for(int i=0;i<N;i++){
        scc_vs[cmp[i]]++;
    }
    for(auto[scc_num,cnt]:scc_vs){
        ans += (cnt*(cnt-1))/2;
    }
    cout << ans << endl;
    // 強連結成分分解を行うと、強連結成分とならない（１点だけで孤立）する点があらわれ、それもcmpにはいる
    // 今回は、cmpないに入っても、 組み合わせの個数なので cnt * (cnt -1) / 2 のところで(cnt -1)==0となるので問題ない
    
}