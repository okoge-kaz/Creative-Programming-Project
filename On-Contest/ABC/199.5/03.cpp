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
int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int>ans(3);
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            for(int k=0;k<N;k++){
                if(i==k || j==k) continue;
                set<int>data;
                for(int v:G[i]) data.insert(v);
                for(int v:G[j]) data.insert(v);
                for(int v:G[k]) data.insert(v);
                if(chmax(cnt,(int)data.size())) ans[0] = i, ans[1] = j, ans[2] = k;
            }
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}