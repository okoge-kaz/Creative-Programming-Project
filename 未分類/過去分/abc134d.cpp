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
    int N;
    cin >> N;
    vector<int>a(N+1);
    for(int i=1;i<=N;i++) cin >> a[i];
    vector<int>b(N+1);
    for(int i=N;i>0;i--){
        int tmp = i;
        int cnt = 0;
        for(int j=2*tmp;j<=N;j+=tmp){
            cnt += b[j];
        }
        if(a[i] == (cnt%2)) b[i] = 0;
        else b[i] = 1;
    }
    int res = 0;
    for(int i=1;i<=N;i++) res += b[i];
    cout << res << endl;
    for(int i=1;i<=N;i++) if(b[i]) cout << i << " ";
    cout << endl;
}