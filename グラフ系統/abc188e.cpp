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
// https://atcoder.jp/contests/abc188/tasks/abc188_e
int main(){
    int N, M;
    cin >> N >> M;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        G[x].push_back(y);
    }
    // DAGでないときでも解ける
    vector<pair<ll,int>>B(N);
    for(int i=0;i<N;i++) B[i] = make_pair(A[i],i);
    sort(B.begin(),B.end());
    vector<bool>seen(N,false);
    ll ans = -INF;
    for(int i=0;i<N;i++){
        ll buy = B[i].first;
        int start = B[i].second;
        queue<int>que; que.push(start);
        while(!que.empty()){
            int now = que.front(); que.pop();
            for(int next:G[now]){
                seen[now] = true;//ここでtrueにするのは、あえて
                if(seen[next]) continue;
                chmax(ans,A[next]-buy);
                que.push(next);
            }
        }
    }
    cout << ans << endl;
}