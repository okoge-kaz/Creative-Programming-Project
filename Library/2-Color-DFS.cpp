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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
vector<ll>col;
vector<vector<ll>>G;
void dfs(ll pos,ll cur){
    col[pos] = cur;
    for(ll v:G[pos]){
        if(col[v]==-1) dfs(v,1-cur);// 初期値は-1とする
        // 1 -cur とすることで 0の時は、次の色を1にできるし、1のときは次の色を0にできる。
    }
}
int main(){
    ll N;
    cin >> N;
    col.resize(N);
    col.assign(N,-1);
    vector<ll>A(N-1),B(N-1);
    for(int i=0;i<N-1;i++) cin >> A[i] >> B[i];
    G.resize(N);
    for(int i=0;i<N-1;i++){
        G[A[i]-1].push_back(B[i]-1);
        G[B[i]-1].push_back(A[i]-1);
    }
    // 2部グラフの性質を用いる問題
    // このタイプの問題を解く際に必要となるライブラリを整備すること
    dfs(0,0);
    vector<ll>ans1,ans2;// ans1,ans2はそれぞれ別の色で塗られる点の集合
    for(int i=0;i<N;i++){
        if(col[i]==1) ans1.push_back(i+1);
        else ans2.push_back(i+1);
    }
    if(ans1.size()>ans2.size()){
        for(int i=0;i<N/2;i++){
            cout << ans1[i] << " ";
        }
        cout << endl;
    }
    else{
        for(int i=0;i<N/2;i++){
            cout << ans2[i] << " ";
            cout << endl;
        }
    }
}