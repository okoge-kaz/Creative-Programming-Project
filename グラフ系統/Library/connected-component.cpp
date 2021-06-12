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

// not verify yet 6/12

// 連結成分ごとに分ける関数
vector<vector<int>> connected_component(const vector<vector<int>> &G){
    int V = (int)G.size();
    vector<vector<int>>ans; vector<bool>seen(V);
    for(int v=0;v<V;v++){
        if(seen[v]) continue;
        queue<int>que; que.push(v); vector<int>tmp;
        tmp.push_back(v);
        while(!que.empty()){
            int crr_v = que.front(); que.pop();
            for(int nv:G[crr_v]){
                if(seen[nv]) continue;
                seen[nv] = true;
                tmp.push_back(nv);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}