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
int N,M;
vector<string>A,B;
bool check(int sy, int sx){
    for(int h=sy;h<sy+M;h++) for(int w=sx;w<sx+M;w++){
        if(A[h][w]!=B[h-sy][w-sx]) return false;
    }
    return true;
}
int main(){
    cin >> N >> M;
    A.resize(N); B.resize(M);
    for(string &e:A) cin >> e; 
    for(string &e:B) cin >> e;

    bool ans = false;
    for(int sy=0;sy<N-M+1;sy++){
        for(int sx=0;sx<N-M+1;sx++){
            ans |= check(sy,sx);
        }
    }
    ans ? cout << "Yes" << endl : cout << "No" << endl;
}