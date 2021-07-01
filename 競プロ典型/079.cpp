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
    int H,W; cin >> H >> W;
    vector<vector<int>>A(H,vector<int>(W));
    vector<vector<int>>B(H,vector<int>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin >> A[i][j];
    for(int i=0;i<H;i++) for(int j=0;j<W;j++) cin >> B[i][j];

    ll cnt = 0;
    for(int i=0;i+1<H;i++){
        for(int j=0;j+1<W;j++){
            int d = B[i][j] - A[i][j];
            cnt += abs(d);
            A[i][j] += d; A[i+1][j] += d;
            A[i][j+1] += d; A[i+1][j+1] += d;
            if(j+1==W-1){
                if(A[i][j+1]!=B[i][j+1]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    cout << cnt << endl;
}