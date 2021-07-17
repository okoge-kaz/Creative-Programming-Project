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
    int N,M; cin >> N >> M;
    vector<int>divisor;
    for(int i=1;i*i<=M;i++){
        if(M%i!=0) continue;
        divisor.push_back(i);
        if(M/i != i) divisor.push_back(M/i);
    }
    sort(divisor.begin(),divisor.end());
    int ans = 0;
    for(int k:divisor){
        if(M/k < N)break;
        chmax(ans,k);
    }
    cout << ans << endl;
}