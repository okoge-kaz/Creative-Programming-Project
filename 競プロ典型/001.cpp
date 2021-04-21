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
ll N,L,K;
vector<ll>A, B;
bool is_OK(ll x){
    int cnt = 0;
    ll tmp = 0;
    for(int i=0;i<=N;i++){
        if(tmp >= x) cnt++, tmp = B[i];
        else{
            tmp += B[i];
        }
    }
    if(tmp >= x) cnt++;

    if(cnt >= K+1) return true;
    else return false;
}
int main(){
    // input
    cin >> N >> L >> K;
    A.resize(N);
    for(int i=0;i<N;i++) cin >> A[i];
    int last = 0;
    for(int i=0;i<N;i++){
        B.push_back(A[i]-last);
        last = A[i];
    } 
    B.push_back(L-last);
    //for(int b:B) cout << b << endl;正常
    // 決めうちして二分探索
    ll ok = INF, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng)/2;
        if(is_OK(mid)){
            ng = mid;
        }
        else ok = mid;
    }
    cout << ng << endl;
}