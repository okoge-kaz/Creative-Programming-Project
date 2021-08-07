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
int N; int si,sj; vector<string>C;
ll r = 0;
clock_t start;
const ll MAX_TIME = 3000000;
string ans;
ll old_score = -INF;

void input(){
    start = clock();
    cin >> N; cin >> si >> sj;
    C.resize(N);
    for(string &e:C) cin >> e;
    // 道路マスの総数をカウント
    for(int i=0;i<N;i++) for(char c:C[i]){
        if(c!='#') r++;
    }
}

ll evaluation(ll v, ll t){
    ll score = 0;
    if(v < r) score += round(1e4 * (ld)v/r);
    else score += round(1e4 + 1e7*(ld)N/t);
    return score;
}

void calc(){
    for(int limit=2;;limit+=2){
        if((clock()-start > 0.95 * MAX_TIME)) return;
        queue<pair<int,int>>que;
        que.push({si,sj});
        while(!que.empty() && (clock()-start < 0.95 * MAX_TIME)){
            int vi = que.front().first; int vj = que.front().second;
            que.pop();
            
        }
    }
}

void output(){
    for(char e:ans) cout << e ;
    cout << endl;
}

int main(){
    input();
    calc();
    output();
}