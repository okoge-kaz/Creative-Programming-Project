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
int main(){
    int N; cin >> N;
    vector<vector<edge>>G(N);
    for(int i=0;i<N-1;i++){
        int a, b; ll c;
        cin >> a >> b >> c;
        a--,b--;
        G[a].push_back(edge(a,b,c));
        G[b].push_back(edge(b,a,c));
    }
    int Q, K; cin >> Q >> K;
    // これの一般版がLCA
    K--;// 0-index

    // Dijkstra
    vector<ll>dist(N,INF);
    dist[K]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    que.push(pair(dist[K],K));
    
    while(!que.empty()){
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();
        if(d > dist[v]) continue;
        for(auto e:G[v]){
            if(chmin(dist[e.to],dist[v]+e.w)){
                que.push(pair(dist[e.to],e.to));
            }
        }
    }

    for(int i=0;i<Q;i++){
        int x,y; cin >> x >> y;
        x--,y--;
        cout << dist[x] + dist[y] << endl;
    }

}