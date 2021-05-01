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
    // 愚直計算量はO(10^11)でとても終わらない
    // ２次元いもす法が活躍する。
    const int len = 1100;
    vector<vector<int>>data(len,vector<int>(len));//いもす法の関係から少し大きめに確保する必要性がある
    for(int i=0;i<N;i++){
        int rx,ry,lx,ly;
        cin >> lx >> ly >> rx >> ry;
        // 座標軸のとり方は、通常の場合と逆なので注意
        data[ly][lx]++;
        data[ly][rx]--;
        data[ry][lx]--;
        data[ry][rx]++;
    }
    // 横方向累積和
    for(int i=0;i<len;i++){
        for(int j=1;j<len;j++){
            data[i][j] += data[i][j-1];
        }
    }
    // 縦方向累積和
    for(int h=1;h<len;h++){
        for(int w=0;w<len;w++){
            data[h][w] += data[h-1][w];
        }
    }
    //重なり
    map<int,int>overwrap;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            overwrap[data[i][j]]++;
        }
    }
    for(int i=1;i<=N;i++){
        cout << overwrap[i] << endl;
    }
}