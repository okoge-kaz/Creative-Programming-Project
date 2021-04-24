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
    ll N, M;
    cin >> N >> M;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];

    map<int,int>cnt;
    set<int>s;
    for(int i=0;i<=M;i++) s.insert(i);
    // setには、mexの答えとなりうるものを保持 M+1種類あるので必ずこの中のうちのどれかが答え

    for(int i=0;i<M;i++){
        if(A[i] <= M){
            cnt[A[i]]++;
            s.erase(A[i]);
        }
    }

    int ans = *s.begin();//これでsetの最前方をとれる
    // setは、内部の要素は狭義の弱順序に従う
    // https://cpprefjp.github.io/reference/set/set.html
    for(int i=1;i<=N-M;i++){
        if(A[i-1] <= M){
            if(cnt[A[i-1]]==1){
                //すなわちこれで範囲内から消える
                cnt.erase(A[i-1]);
                s.insert(A[i-1]);
            }
            else cnt[A[i-1]]--;
        }
        if(A[i+M-1] <= M){
            cnt[A[i+M-1]]++;
            s.erase(A[i+M-1]);
        }
        ans = min(ans, *s.begin());
    }
    cout << ans << endl;
}