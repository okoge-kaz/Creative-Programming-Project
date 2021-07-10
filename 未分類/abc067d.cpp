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
int main(){
    int N; cin >> N;
    vector<vector<int>>G(N);
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        a--,b--; G[a].push_back(b); G[b].push_back(a);
    }
    vector<bool>seen(N,false);
    queue<int>que; que.push(0); que.push(N-1);
    vector<int>color(N); color[0] = 1; color[N-1] = -1;
    seen[0] = true; seen[N-1] = true;

    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int nv:G[v]){
            if(seen[nv]) continue;
            seen[nv] = true;
            if(color[v]==1) color[nv] = 1;
            else color[nv] = -1;
            que.push(nv);
        }
    }

    int sunuke = 0; int feneke = 0;
    for(int i=0;i<N;i++){ if(color[i]==1) feneke++; else sunuke++; }
    if(feneke > sunuke) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}