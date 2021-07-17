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
int dy[] = {1, 0}, dx[] = {0, 1};
int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    int H,W; cin >> H >> W;
    vector<vector<int>>a(H,vector<int>(W));
    for(int i=0;i<H;i++) for(int j=0;j<W;j++){
        cin >> a[i][j];
    }
    // 貪欲法でできるが、その方法がうまく思いつかなかった
    vector<tuple<int,int,int,int>>ans;
    for(int i=0;i<H;i++){
        for(int j=0;j<W-1;j++){
            if(a[i][j]%2==1){
                a[i][j]--; a[i][j+1]++;
                ans.push_back(tuple(i+1,j+1,i+1,j+2));
            }
        }
    }
    for(int i=0;i<H-1;i++){
        if(a[i][W-1]%2==1){
            a[i][W-1]--; a[i+1][W-1]++;
            ans.push_back(tuple(i+1,W,i+2,W));
        }
    }
    cout << (int)ans.size() << endl;
    for(auto[y,x,ny,nx]:ans){
        cout << y << " " << x << " " << ny << " " << nx << endl;
    }
}