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
using lll = __int128_t;
int n,q;
vector<vector<int>>G;
vector<int>color;
bool flg = true;
void dfs(int v,int par){
    for(int nv:G[v]){
        if(nv==par) continue;
        if(color[nv]!=-1){
            if(color[nv]==color[v]) flg = false;
        }
        color[nv] = (1-color[v]);
        dfs(nv,v);
    }
}
int main(){
    // LCAを使って解けばすぐだがあえて別の方法で解く
    // 2部グラフ
    cin >> n >> q;
    G.resize(n); color.resize(n,-1);
    // 木なので閉路はないので2部グラフであることが保証されている
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        --a,--b;
        G[a].push_back(b); G[b].push_back(a);
    }
    color[0] = 0;
    dfs(0,-1);
    if(!flg){
        cout << "error" << endl;
    }
    while(q-->0){
        int c,d; cin >> c >> d;
        --c,--d;
        if(color[c]==color[d]){
            cout << "Town" << endl;
        }
        else cout << "Road" << endl;
    }
}