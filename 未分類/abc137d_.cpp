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
    // reference is snuke's submission
    int n,m; cin >> n >> m;
    vector<vector<int>>jobs(m+1);
    for(int i=0;i<n;i++){
        int a,b; cin >> a >> b;
        if(a>m) continue;
        jobs[a].push_back(b);
    }
    priority_queue<int>que;
    int ans = 0;
    for(int crr=m;crr>=0;crr--){
        // crr: crr 日目 crr stands for current day
        for(int b:jobs[m-crr]){
            que.push(b);
        }
        if(!que.empty()){
            // queue や priority_queueのときにこの処理を書かないとバグの原因
            ans += que.top(); que.pop();
        }
    }
    cout << ans << endl;
}