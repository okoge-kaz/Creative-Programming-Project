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
int N; vector<int>A,B;
vector<vector<int>>G; vector<ll>c;
void dfs(int v, int par,ll x){
    for(int nv:G[v]){
        if(nv==par) continue;
        dfs(nv,v,x);
        c[nv]+=x;
    }
    return;
}
// DFS * query = 計算量 QN 
int main(){
    cin >> N;
    G.resize(N); A.resize(N-1); B.resize(N-1);
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        a--,b--; G[a].push_back(b); G[b].push_back(a);
        A[i] = a, B[i] = b;
    }
    int Q; cin >> Q; c.resize(N);
    for(int q=0;q<Q;q++){
        int t,e; ll x;
        cin >> t >> e >> x; e--;
        if(t==1){
            c[A[e]]+=x;
            for(int v:G[A[e]]){
                if(v==B[e]) continue;
                c[v]+=x;
                dfs(v,A[e],x);
            }
        }
        else{
            c[B[e]] += x;
            for(int v:G[B[e]]){
                if(v==A[e]) continue;
                c[v]+=x;
                dfs(v,B[e],x);
            }
        }
    }
    for(ll e:c) cout << e << endl;
}