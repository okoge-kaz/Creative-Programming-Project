#include <bits/stdc++.h>
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
    int n; cin >> n;
    vector<vector<int>>g(n);
    vector<vector<int>>G(n,vector<int>(n));
    for(int i=0;i<n;i++){
        int k,l; cin >> k >> l;
        for(int j=0;j<l;j++){
            int e; cin >> e;
            e--;
            g[i].push_back(e);
        }
    }
    for(int i=0;i<n;i++){
        for(int node:g[i]){
            G[i][node]++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j==n-1){
                cout << G[i][j] ;
                continue;
            }
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}