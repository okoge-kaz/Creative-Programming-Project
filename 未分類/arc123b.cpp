#include <bits/stdc++.h>
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
    int n; cin >> n;
    vector<int>a(n),b(n),c(n);
    for(int &e:a) cin >> e;
    for(int &e:b) cin >> e;
    for(int &e:c) cin >> e;
    sort(a.begin(),a.end()); sort(b.begin(),b.end()); sort(c.begin(),c.end());

    int b_id = 0; int c_id = 0;
    int index = -1;
    for(int i=0;i<n;i++){
        // b[j] > a[i]
        while(b[b_id]<=a[i] && b_id < n) b_id++;
        if(b[b_id] <= a[i]){ index = max(index,(i-1)); break; }
        // c[k] > b[j]
        while(c[c_id]<=b[b_id] && c_id < n) c_id++;
        if(c[c_id] <= b[b_id]){ index = max(index,(i-1)); break; }
        // next i
        b_id++; c_id++;
        index = i;
    }
    cout << index+1 << endl;
}