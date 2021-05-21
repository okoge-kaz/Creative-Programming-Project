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
struct edge{
    ll from; ll to; ll c;
    edge(ll from, ll to, ll c) : from(from), to(to), c(c) {}
};
int main(){
    ll N, M;
    cin >> N >> M;
    vector<vector<edge>>edges(N);
    for(int i=0;i<M;i++){
        ll p,q,c;
        cin >> p >> q >> c;
        p--,q--;
        edges[p].push_back(edge(p,q,c));// 双方向に結んでいるので
        edges[q].push_back(edge(q,p,c));
    }

    vector dist(N,INF);
    dist[0] = 0LL; 
    deque<pair<ll,ll>>que;
    que.push_back({0,-1});// 今どこにいるのか、どの会社の路線を使ったのか

    while(!que.empty()){
        auto [now, com] = que.front(); que.pop_front();
        for(auto[from,to,c]:edges[now]){
            if(c==com){
                if(chmin(dist[to],dist[now])){
                    que.push_front({to,c});
                }
            }
            else{
                if(chmin(dist[to],dist[now]+1LL)){
                    que.push_back({to,c});
                }
            }
        }
    }

    if(dist[N-1]==INF) cout << -1 << endl;
    else cout << dist[N-1] << endl;
}