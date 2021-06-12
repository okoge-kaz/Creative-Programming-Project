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
// トポロジカルソート

class Topological_Sort {
    private:
        int N,M;// N: 頂点数, M: 辺数
        vector<bool>seen; vector<int>order;// トポロジカルソート順を格納
        vector<vector<int>>G;
        bool graph_set = false; bool is_build = false;
        void rec(const vector<vector<int>>&Graph, int v){
            // 深さ優先探索
            seen[v] = true;
            for(auto nv: Graph[v]){
                if(seen[nv]) continue;
                rec(Graph, nv);
            }
            order.push_back(v);//帰りがけ
        }
    public:
        Topological_Sort(int V, int E) : N(V), M(E) ,seen(N,false), G(N) {}

        void set(vector<vector<int>> &Graph){
            G = Graph;
            graph_set = true;
        }
        void buid(){
            assert(graph_set && "graph is not set");
            is_build = true;
            
            for(int v=0;v<N;v++){
                if(seen[v]) continue;
                rec(G,v);
            }
        }
        vector<int> res(){
            assert(graph_set && "graph is not set");
            assert(is_build && "is not built");

            reverse(order.begin(),order.end());// トポロジカルソート順に直す
            return order;
        }
};