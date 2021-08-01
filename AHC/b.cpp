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

int D;
vector<ll>c(26);
vector<vector<ll>>s;

void input(){
    cin >> D;
    for(int i=0;i<26;i++) cin >> c[i];
    s.resize(D,vector<ll>(26));
    for(int i=0;i<D;i++){
        for(int j=0;j<26;j++){
            cin >> s[i][j];
        }
    }
}

void calculateScore(vector<ll>&t){
    ll res = 0;
    vector<int>last(26,0);
    for(int i=0;i<D;i++){
        res += s[i][t[i]-1];
        // 満足度の低下
        last[t[i]-1] = i+1;
        for(int j=0;j<26;j++){
            res -= c[j] * (i+1 - last[j]);
        }
        cout << res << endl;
    }
}

int main(){
    // input 
    input();
    vector<ll>t(D); 
    for(int i=0;i<D;i++) cin >> t[i];
    // calculation
    calculateScore(t);
}