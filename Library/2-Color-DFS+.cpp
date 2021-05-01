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
// 2色の塗り分け系統問題
// 参考 ABC 198 E https://atcoder.jp/contests/abc198/submissions/21791407

vector<vector<int>>G;// 隣接グラフで保存
vector<int>col;// 色を保存する
vector<bool>used;// すでに見たかどうかを保存
vector<int>vs;// 連結成分ごとに分けるため（連結成分ごとに初期化）
// 連結成分ごとに初期化したくないなら vector<vector<int>> のようにしてもつしかない

// この問題では、現在の点までに通った点の色の数を保持する必要がある。
const int color_num = 110000;// 色の最大個数
vector<int>cnt(color_num);// 各色の頂点の個数

// 木の場合は、すべてが連結なことが保証されているが、そうでない場合は連結成分ごとに分ける
void dfs(int v){// このdfsは、連結成分に分ける用
    if(used[v]) return;
    used[v] = true;
    vs.push_back(v);
    for(int nv:G[v]){
        dfs(nv);//次の頂点へ
    }
}

// usedを用いて書くと最短経路出ない場合に漏れが生じる
void dfs2(int v, vector<int> &cnt, vector<bool> &is_good, ll pa = -1 ){
    // paはデフォルト引数 デフォルト引数は一番最後に書く!
    // G グラフ構造（隣接グラフ）, crt 現在の頂点, cnt 各色の個数, is_good いい頂点か否か
    if(cnt[col[v]] == 0) is_good[v] = true;
    cnt[col[v]]++;
    //
    for(ll nv:G[v]){
        if(nv==pa) continue;// 前に戻る時
        dfs2(nv, cnt, is_good, v);// vを書くのは、戻って来ないように
    }
    // その頂点を通る場合から外れるため
    cnt[col[v]]--;
    return;
}
 
int main(){
    ll N;
    cin >> N;

    // グラフをとってくる
    col.resize(N);
    used.resize(N);
    used.assign(N,false);
    for(int i=0;i<N;i++) cin >> col[i];
    vector<pair<int,int>>AB(N-1);
    for(int i=0;i<N-1;i++){
        // 0-index
        int A,B;
        cin >> A >> B;
        --A,--B;
        AB[i].first = A, AB[i].second = B;
    }
    G.resize(N);
    for(int i=0;i<N-1;i++){
        G[AB[i].first].push_back(AB[i].second);
        G[AB[i].second].push_back(AB[i].first);
    }

    // 以降処理
    vector<bool>is_good(N,false);// 各頂点がいい頂点かどうか
    dfs2(0, cnt, is_good);
    for(int i=0;i<N;i++) if(is_good[i]) cout << i+1 << endl;
}