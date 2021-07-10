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
    ll N; string S; cin >> N >> S;
    ll ans = 0; ll o = 0, x = 0;
    for(int i=0;i<N;i++){
        if(S[i]=='o'){
            // ランレングス圧縮
            ans += x * (x+1) / 2; x = 0;
            o++;
        }
        else{
            ans += o * (1+o) / 2; o = 0;
            x++;
        }
    }
    ans += x * (x+1) / 2; ans += o * (1+o) / 2;
    cout << (ll)N * (N+1) / 2 - ans << endl;
}