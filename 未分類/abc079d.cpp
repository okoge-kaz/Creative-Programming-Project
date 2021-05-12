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
    int H,W;
    cin >> H >> W;
    // ワーシャル・フロイド法の練習問題
    // このようなタイプの問題は全点対最短経路問題として知られているらしい
    vector<vector<int>>c(10,vector<int>(10));
    for(int i=0;i<10;i++)for(int j=0;j<10;j++) cin >> c[i][j];
    // ワーシャル・フロイド
    // 計算量はO(V^3)つまり頂点数の３重ループ
    for(int k=0;k<10;k++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                c[i][j] = min(c[i][j],c[i][k] + c[k][j]);
            }
        }
    }
    // 計算量がO(V^3)なので頂点数が小さい場合はワーシャル・フロイド法を疑うべし
    ll cost = 0;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            int a;
            cin >> a;
            if(a==-1) continue;
            cost += c[a][1];
        }
    }
    cout << cost << endl;
}