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
    int N,Q; cin >> N >> Q;
    vector<ll>A(N); for(int i=0;i<N;i++) cin >> A[i];
    ll sum = 0; for(int i=1;i<N;i++) sum += abs(A[i]-A[i-1]);
    vector<ll>B(N);
    B = A;
    // 絶対値の端っこしか影響を及ぼさない。でも一つの配列だけではうまくいかないので２つ用意する
    for(int i=0;i<Q;i++){
        ll L,R,V; cin >> L >> R >> V;
        L--,R--;
        if(L-1>=0){
            sum -= abs(A[L]-B[L-1]);
            A[L] += V;
            sum += abs(A[L]-B[L-1]);
        }
        if(R+1<N){
            sum -= abs(A[R+1]-B[R]);
            B[R] += V;
            sum += abs(A[R+1]-B[R]);
        }
        cout << sum << endl;
    }
}