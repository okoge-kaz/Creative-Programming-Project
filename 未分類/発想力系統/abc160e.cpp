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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll>p(A), q(B), r(C);
    for(int i=0;i<A;i++) cin >> p[i];
    for(int i=0;i<B;i++) cin >> q[i];
    for(int i=0;i<C;i++) cin >> r[i];

    priority_queue<ll>que;
    sort(p.begin(),p.end(),greater<ll>()); sort(q.begin(),q.end(),greater<ll>()); sort(r.begin(),r.end(),greater<ll>());
    // この問題で着目するべきなのは、X < A && Y < B であること
    for(int i=0;i<X;i++) que.push(p[i]); 
    for(int i=0;i<Y;i++) que.push(q[i]);
    for(int i=0;i<C;i++) que.push(r[i]);
    // 最低でも、赤のりんごをX個、緑のリンゴをY個queに入れておけば、必ず条件を満たす。

    ll ans = 0LL;
    for(int i=0;i<X+Y;i++){
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
}