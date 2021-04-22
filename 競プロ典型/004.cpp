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
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>>A(H,vector<ll>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }
    vector<ll>col(W), row(H);
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            row[h] += A[h][w];
        }
    }
    for(int w=0;w<W;w++){
        for(int h=0;h<H;h++){
            col[w] += A[h][w];
        }
    }
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            cout << col[w] + row[h] - A[h][w] << " ";
        }
        cout << endl;
    }
}