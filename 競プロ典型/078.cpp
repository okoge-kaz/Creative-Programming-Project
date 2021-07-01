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
int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int a,b; cin >> a >> b;
        --a,--b;
        G[a].push_back(b); G[b].push_back(a);
    }
    int cnt = 0;
    for(int i=0;i<N;i++){
        int tmp = 0;
        for(int v:G[i]){
            if(v<i) tmp++;
        }
        if(tmp==1) cnt++;
    }
    cout << cnt << endl;
}