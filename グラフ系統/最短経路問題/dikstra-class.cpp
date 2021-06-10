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

// not verify 

class Dijkstra {
    class edge {
        public:
            int from; int to; ll w;
            edge(int from, int to, ll w) : from(from), to(to), w(w) {}
    };
    using Graph = vector<vector<edge>>;
    private:
        int N; int M; int s;
        Graph G;
        bool graph_set = false;
        vector<ll> prev;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
    public:
        vector<ll>dist;
        Dijkstra(int V, int E) : N(V), M(E), G(N), dist(N,INF),prev(N,-1LL) {}
        void set(Graph g){
            G = g;
            graph_set = true;
        }
        void start_set(int st){
            s = st;
            dist[st] = 0;
        }
        void build(){
            que.push(make_pair(dist[s], s));
            while(!que.empty()){
                int v = que.top().second;
                ll d = que.top().first;
                que.pop();
                if(d > dist[v]) continue;
                for(auto e:G[v]){
                    if(chmin(dist[e.to],dist[v] + e.w)){
                        que.push(make_pair(dist[e.to],e.to));
                        prev[e.to] = v;// vを通って e.toに辿り着いた
                    }
                }
            }
        }
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
};

class edge {
    public:
        int from; int to; ll w;
        edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
using Graph = vector<vector<edge>>;

int main(){
    
}