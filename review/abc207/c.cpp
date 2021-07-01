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
    // この手の問題には定石がある
    int N; cin >> N;
    vector<int>t(N); vector<ld>l(N),r(N);
    for(int i=0;i<N;i++){
        cin >> t[i] >> l[i] >> r[i];
        if(t[i]==1) continue;
        if(t[i]==2) r[i] -= 0.5;
        if(t[i]==3) l[i] += 0.5;
        if(t[i]==4) l[i] += 0.5, r[i] -= 0.5;
    }

    int cnt = 0;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++){
        if(!(r[j] < l[i] || r[i] < l[j])) cnt++;
    }
    cout << cnt << endl;
}