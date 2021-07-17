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

void dfs(vector<vector<int>>&G,vector<bool>&seen,int v,ll &cnt){
    // 先にseen[v] = true;としてしまうとreturn してしまってseen[v] = falseと直すところがなくなってしまう
    // 終了条件
    bool end = true;
    for(int i=0;i<(int)seen.size();i++){
        if(!seen[i] && i!=v) end = false;
    }
    if(end){ cnt++; return; }

    seen[v] = true;
    for(int nv:G[v]){
        if(seen[nv]) continue;
        dfs(G,seen,nv,cnt);
    }
    seen[v] = false;
}

int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        a--,b--;
        G[a].push_back(b); G[b].push_back(a);
    }
    ll cnt = 0;
    vector<bool>seen(N,false);
    dfs(G,seen,0,cnt);
    cout << cnt << endl;
}