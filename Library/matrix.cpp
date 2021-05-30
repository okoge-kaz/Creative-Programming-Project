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
// 行列計算のためのテンプレート
// 行列の掛け算
template <typename T>
vector<vector<T>> matrix_mult(vector<vector<T>> &A, vector<vector<T>> &B){
    vector<vector<T>> res((int)A.size(),vector<T>((int)B[0].size()));//返値
    for(int i=0;i<(int)A.size();i++){
        for(int k=0;k<(int)B.size();k++){
            for(int j=0;j<(int)B[0].size();j++){
                res[i][j] += A[i][k] * B[k][j];// MODが必要な場合はここに追加 
            }
        }
    }
    return res;
}

// 行列の冪乗
// A^nを計算
template <typename T>
vector<vector<T>> matrix_pow(vector<vector<T>> &A, ll n){
    vector<vector<T>> res((int)A.size(),vector<T>((int)A.size()));
    // 冪乗できるので当然正方行列
    for(int i=0;i<(int)A.size();i++){
        res[i][i] = 1;
    }// 単位行列をつくる
    while(n>0){
        if(n & 1) res = matrix_mult(res,A);
        A = matrix_mult(A,A);
        n = (n >> 1);
    }// 繰り返し二乗法を用いているので計算量 0(log(N) * A.size()^3)
    return res;
}