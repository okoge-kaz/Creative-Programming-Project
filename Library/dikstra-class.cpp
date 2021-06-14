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

// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A

class edge {
    public:
        int from; int to; ll w;
        edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};

class Dijkstra {
    private:
        int s;
        vector<vector<edge>> G;
        bool is_start_set = false;
        vector<ll> prev;  vector<ll>dist;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que;
        void init(int N, int M, const vector<vector<edge>> &Graph){
            dist.assign(N,INF); prev.assign(N,-1LL);
            G = Graph;
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
            is_start_set = true;
        }
    public:
        Dijkstra(int V, int E, const vector<vector<edge>> &Graph) { init(V,E,Graph); }
        void start_set(int st){
            s = st;
            dist[st] = 0;
            build();
        }
        vector<ll> get_dist(){
            assert(is_start_set && "please set start point");
            return dist;
        }
        vector<ll> get_path(ll g){
            assert(is_start_set && "please set start point");
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

int main(){
    int V, E, r; cin >> V >> E >> r;
    vector<vector<edge>>G(V);
    for(int i=0;i<E;i++){
        int s, t; ll d; cin >> s >> t >> d;
        G[s].push_back(edge(s,t,d));
    }
    Dijkstra dijkstra(V,E,G);
    dijkstra.start_set(r);
    auto ans = dijkstra.get_dist();
    for(ll e:ans){
        if(e==INF) cout << "INF" << endl;
        else cout << e << endl;
    }
}