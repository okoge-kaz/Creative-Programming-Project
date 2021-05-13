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
    vector<vector<int>>data(1100,vector<int>(1100));
    for(int i=0;i<N;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        data[y1][x1]++;
        data[y1][x2]--;
        data[y2][x1]--;
        data[y2][x2]++;
    }
    int ans = 0;
    for(int h=0;h<=1000;h++){
        for(int w=0;w<=1000;w++){
            data[h][w+1] += data[h][w];
        }
    }
    for(int w=0;w<=1000;w++){
        for(int h=0;h<=1000;h++){
            data[h+1][w] += data[h][w];
        }
    }
    for(int h=0;h<=1000;h++){
        for(int w=0;w<=1000;w++){
            chmax(ans,data[h][w]);
        }
    }
    cout << ans << endl;
}