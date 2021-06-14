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
// verify https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
// ダイクストラを用いているので当然負辺があると使えない

struct edge {
    int from; int to; ll w;
    edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
ll tree_diameter(const vector<vector<edge>>&G1, const vector<vector<edge>>&G2){
    // G2はG1の有向辺を逆向きにしたもの
    int N = (int)G1.size();
    vector<ll>dist1(N,INF), dist2(N,INF);
    // 適当にスタート地点をs=0とする
    int s = 0; dist1[s]=0; 
    // ダイクストラ
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que1;
    que1.push(pair(dist1[s],s));
    while(!que1.empty()){
        int v = que1.top().second; ll d = que1.top().first;
        que1.pop();
        if(d > dist1[v]) continue;
        for(auto e:G1[v]){
            if(chmin(dist1[e.to],dist1[v]+e.w)){
                que1.push(pair(dist1[e.to],e.to));
            }
        }
    }
    // ダイクストラ終了
    int end_point = -1;//端点
    ll longest_path = -1;
    for(int i=0;i<N;i++){
        if(chmax(longest_path,dist1[i])){
            end_point = i;
        }
    }
    // ダイクストラ2回目
    s = end_point;
    dist2[s]=0LL;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> que2;
    que2.push(pair(dist2[s],s));
    while(!que2.empty()){
        int v = que2.top().second; ll d = que2.top().first;
        que2.pop();
        if(d > dist2[v]) continue;
        for(auto e:G2[v]){
            if(chmin(dist2[e.to],dist2[v]+e.w)){
                que2.push(pair(dist2[e.to],e.to));
            }
        }
    }
    ll ans = -1;
    for(int i=0;i<N;i++) chmax(ans,dist2[i]);
    return ans;
}
int main(){
    int N; cin >> N;
    vector<vector<edge>>G1(N), G2(N);
    for(int i=0;i<N-1;i++){
        int s, t; cin >> s >> t;
        ll w; cin >> w;
        // 無向グラフなので
        G1[s].push_back(edge(s,t,w));
        G1[t].push_back(edge(t,s,w));
        G2[s].push_back(edge(s,t,w));
        G2[t].push_back(edge(t,s,w));
    }
    cout << tree_diameter(G1,G2) << endl;
}