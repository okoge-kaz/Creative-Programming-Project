#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;
struct edge {
    int from; int to; ll w;
    edge(int from, int to, ll w) : from(from), to(to), w(w) {}
};
// 参考 https://atcoder.jp/contests/abc201/tasks/abc201_e/editorial
int main(){
    ll N; cin >> N;
    vector<vector<edge>>G(N);
    for(int i=0;i<N-1;i++){
        ll u,v,w; cin >> u >> v >> w;
        u--,v--;
        G[u].push_back(edge(u,v,w));
        G[v].push_back(edge(v,u,w));
    }
    // XOR距離なのでダイクストラでは、うまくいかない
    vector<ll> dist1(N,INF);
    dist1[0] = 0;// 始点 XORにおいて0は単位元なので通常の最短経路問題のように0として大丈夫
    queue<int>que; que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        for(auto[from, to, w]:G[now]){
            if(chmin(dist1[to],dist1[now]^w)){// 更新があるならば、入れる
                que.push(to);
            }
        }
    }
    // XORの演算があったら桁ごとに考えるのはかなり典型
    mint ans = 0;
    for(int i=0;i<60;i++){
        ll cnt0 = 0; ll cnt1 = 0;
        for(int j=0;j<N;j++){
            if((dist1[j]) & (1LL << i) ) cnt1++;// dist[j]のi桁目（bit桁）が1かどうか
            // bit演算の時は 1LL << の1LLを忘れずに
            else cnt0++;
        }
        ans += (mint)(1LL << i) * (mint)(cnt1) * (mint)(cnt0);
    }
    cout << ans.val() << endl;
}