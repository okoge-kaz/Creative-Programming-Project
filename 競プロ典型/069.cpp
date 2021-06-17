#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
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
using mint = modint1000000007;
int main(){
    ll N, K; cin >> N >> K;
    if(K<=2 && N > 2){
        cout << 0 << endl;
        return 0;
    }
    if(K<=2){
        mint res = 1;
        if(N==1){
            cout << (res*K).val() << endl;
            return 0;
        }
        if(N==2){
            cout << (res*K*(K-1)).val() << endl;
            return 0;
        }
    }
    if(N<=2){
        mint res = 1;
        if(N==1){
            cout << (res*K).val() << endl;
            return 0;
        }
        else{
            cout << (res*K*(K-1)).val() << endl;
            return 0;
        }
    }
    mint ans = K * (K-1);
    cout << (ans * ((mint)(K-2)).pow(N-2)).val() << endl;
}