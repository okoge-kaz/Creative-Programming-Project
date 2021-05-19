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

struct edge {
    int from; int to; ll w;
    edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
using Graph = vector<vector<edge>>;

// 経路復元用途
vector<ll> get_path(const vector<ll> &prev, ll g){
    // 方針としては、終点g から始点 sまで逆に辿る
    vector<ll> path;
    for(int cur = g; cur != -1;cur = prev[cur]){
        // -1 (= 始点)に戻るまで、prevで逆に戻る
        path.push_back(cur);
    }
    reverse(path.begin(),path.end());
    return path;
}

int main(){
    
    ll N, M, T;
    cin >> N >> M >> T;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    // 行って戻ってくるタイプの最短経路問題の時には、辺の向きを逆にするという手法が取られる。
    Graph G1(N);
    Graph G2(N);
    for(int i=0;i<M;i++){
        int a,b,w;
        cin >> a >> b >> w;
        --a,--b;
        G1[a].push_back(edge(a,b,w));
        G2[b].push_back(edge(b,a,w));
    }

    // ダイクストラ法
    vector<ll> dist1(N,INF);
    dist1[0] = 0;// 始点
    vector<ll> prev(N,-1);// 経路復元
    
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que1;
    que1.push(make_pair(dist1[0], 0));

    // ダイクストラ法の反復を開始
    while(!que1.empty()){
        // v: 使用済みでない頂点のうち d[v]が最小
        // d: vに対するキー値
        int v = que1.top().second;
        ll d = que1.top().first;
        que1.pop();

        // d > dist[v] は、(d,v)がゴミであることを表す = 最短経路でないもの
        if(d > dist1[v]) continue;

        // 頂点v を始点とした各辺を緩和
        for(auto e:G1[v]){
            if(chmin(dist1[e.to],dist1[v] + e.w)){
                // 更新があるならヒープに新たに挿入
                que1.push(make_pair(dist1[e.to],e.to));
                // 経路復元用
                prev[e.to] = v;// vを通って e.toに辿り着いた
            }
        }
    }

    // ダイクストラ法
    vector<ll> dist2(N,INF);
    dist2[0] = 0;// 始点
    
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que2;
    que2.push(make_pair(dist2[0], 0));

    // ダイクストラ法の反復を開始
    while(!que2.empty()){
        // v: 使用済みでない頂点のうち d[v]が最小
        // d: vに対するキー値
        int v = que2.top().second;
        ll d = que2.top().first;
        que2.pop();

        // d > dist[v] は、(d,v)がゴミであることを表す = 最短経路でないもの
        if(d > dist2[v]) continue;

        // 頂点v を始点とした各辺を緩和
        for(auto e:G2[v]){
            if(chmin(dist2[e.to],dist2[v] + e.w)){
                // 更新があるならヒープに新たに挿入
                que2.push(make_pair(dist2[e.to],e.to));
            }
        }
    }

    vector sum(N,0LL);
    ll ans = 0;
    for(int i=0;i<N;i++){
        sum[i] = max(T - dist1[i] - dist2[i],0LL) * A[i];
        chmax(ans,sum[i]);
    }
    cout << ans << endl;
    
}