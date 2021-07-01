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
// 木において（有向辺）各点からの最長距離（木の高さ）を求める 
// 計算量 4 * N (log N) (定数倍がかなり重い)
// verified https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B

struct edge {
    int from; int to; ll w;
    edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
class Tree_hight {
    private:
        vector<vector<edge>>G1,G2;
        vector<ll>dist1,dist2;
        vector<ll>hight; int N;
        ll diameter = -1;
        // 各頂点からの最長距離と、木の直径の両方をもつ
        void init(const vector<vector<edge>> &G){
            // 計算量 4 * N log(N)
            N = (int)G.size();
            G1.resize(N); G2.resize(N);
            dist1.assign(N,INF); dist2.assign(N,INF);
            hight.resize(N);
            for(int v=0;v<N;v++){
                for(edge e:G[v]){
                    G1[v].push_back(e);
                    G2[e.to].push_back(edge(e.to,e.from,e.w));
                    //逆向きにする
                }
            }
            // ダイクストラ
            int s = 0; dist1[s]=0;
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>que1;
            que1.push(pair(dist1[s],s));
            while(!que1.empty()){
                int v = que1.top().second; ll d = que1.top().first;
                que1.pop();
                if(d>dist1[v]) continue;
                for(edge e:G1[v]){
                    if(chmin(dist1[e.to],dist1[v]+e.w)){
                        que1.push(pair(dist1[e.to],e.to));
                    }
                }
            }
            // 端点を探す
            int end_point1 = -1; int end_point2 = -1;
            ll longest_path = -1;
            for(int i=0;i<N;i++){
                if(chmax(longest_path,dist1[i])) end_point1 = i;
            }
            // ダイクストラ2回目
            s = end_point1;
            dist2[s] = 0;
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>que2;
            que2.push(pair(dist2[s],s));
            while(!que2.empty()){
                int v = que2.top().second; ll d = que2.top().first;
                que2.pop();
                if(d>dist2[v])continue;
                for(edge e:G2[v]){
                    if(chmin(dist2[e.to],dist2[e.from]+e.w)){
                        que2.push(pair(dist2[e.to],e.to));
                    }
                }
            }
            for(int i=0;i<N;i++) if(chmax(diameter,dist2[i])) end_point2 = i;
            // これで直径がもとまった
            vector<ll>dist3(N,INF),dist4(N,INF);
            // 木の高さを求める
            // ダイクストラ
            dist3[end_point1]=0;
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>que3;
            que3.push(pair(dist3[end_point1],end_point1));
            while(!que3.empty()){
                int v = que3.top().second; ll d = que3.top().first;
                que3.pop();
                if(d>dist3[v])continue;
                for(edge e:G1[v]){
                    if(chmin(dist3[e.to],dist3[v]+e.w)){
                        que3.push(pair(dist3[e.to],e.to));
                    }
                }
            }
            // ダイクストラ
            dist4[end_point2]=0;
            priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>que4;
            que4.push(pair(dist4[end_point2],end_point2));
            while(!que4.empty()){
                int v = que4.top().second; ll d = que4.top().first;
                que4.pop();
                if(d>dist4[v])continue;
                for(edge e:G1[v]){
                    if(chmin(dist4[e.to],dist4[e.from]+e.w)){
                        que4.push(pair(dist4[e.to],e.to));
                    }
                }
            }
            // 各点の高さを出す
            for(int i=0;i<N;i++) hight[i] = max(dist3[i],dist4[i]);
        }
    public:
        Tree_hight(const vector<vector<edge>> &G) { init(G); }
        ll get_tree_diameter(){
            return diameter;
        }
        vector<ll> get_tree_hight(){
            return hight;
        }
};
int main(){
    int N; cin >> N;
    vector<vector<edge>>G(N);
    for(int i=0;i<N-1;i++){
        int s,t; ll w;
        cin >> s >> t >> w;
        G[s].push_back(edge(s,t,w));
        G[t].push_back(edge(t,s,w));
    }
    Tree_hight trees(G);
    auto vec = trees.get_tree_hight();
    for(ll h:vec)cout << h << endl;
}