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

// 解説 https://atcoder.jp/contests/abc187/tasks/abc187_e/editorial
// https://drken1215.hatenablog.com/entry/2021/01/03/162800

int N; vector<vector<int>>G; vector<int>A,B;
vector<int>depth;

void dfs(int v,int par,int d){
    depth[v] = d;
    for(int nv:G[v]){
        if(nv==par)continue;
        dfs(nv,v,d+1);
    }
    return;
}

int main(){
    cin >> N; G.resize(N);
    A.resize(N-1),B.resize(N-1); depth.resize(N);
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        a--,b--; G[a].push_back(b); G[b].push_back(a);
        A[i] = a; B[i] = b;
    }
    dfs(0,-1,0);// 適当に頂点0を根にする

    vector<ll>sum(N);// いもす法のようにする
    int Q; cin >> Q;
    while(Q-->0){
        // Q自体をつかわないクエリのような時に便利な記法
        ll t,e,x; cin >> t >> e >> x; e--;
        if(t==1){
            if(depth[A[e]]<depth[B[e]]){
                sum[0] += x; sum[B[e]] -= x;
            }
            else{
                sum[A[e]] += x;// A[e]とB[e]は近接であることより
            }
        }
        else{
            if(depth[B[e]]<depth[A[e]]){
                sum[0] += x; sum[A[e]] -= x;
            }
            else{
                sum[B[e]] += x;
            }
        }
    }

    queue<int>que; que.push(0);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv:G[v]){
            if(depth[nv] > depth[v]){
                sum[nv] += sum[v];// 深さがより深いところにしか伝搬しない
                que.push(nv);
            }
        }
    }
    for(ll e:sum) cout << e << endl;
}