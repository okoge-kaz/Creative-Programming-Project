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
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    // 問題文の言い換えがものを言うタイプの問題
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(i-1>=0){
            if(s[i-1]!=s[i]) cnt++;
        } 
    }
    cout << N - 1  - max(cnt-K*2,0) << endl;
}