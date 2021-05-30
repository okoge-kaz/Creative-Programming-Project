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

int main(){
    int N; cin >> N;
    vector<int>X(N), Y(N);
    for(int i=0;i<N;i++) cin >> X[i] >> Y[i];
    int M; cin >> M;
    vector<pair<int,int>>op(M);
    for(int i=0;i<M;i++){
        int m; cin >> m; op[i].first = m;
        if(m==3 || m==4){
            int p; cin >> p; op[i].second = p;
        }
    }
    int Q; cin >> Q;
    vector<int>A(Q); vector<int>B(Q);
    for(int i=0;i<Q;i++) cin >> A[i] >> B[i];

    vector sum(M+1,vector(3, vector(3,0LL)));// 累積積
    vector ops(5,vector(3,vector(3,0LL)));// オペレーション

    ops[1] = {{0,1,0},{-1,0,0},{0,0,1}};
    ops[2] = {{0,-1,0},{1,0,0},{0,0,1}};

    sum[0][0][0] = 1, sum[0][1][1] = 1, sum[0][2][2] = 1;
    for(int i=0;i<M;i++){
        if(op[i].first ==1){
            sum[i+1] = matrix_mult(ops[1],sum[i]);//順番注意
            // ここでops * sum の順番になっているのは、対応する行列を左からかける形式で求めたため
        }
        if(op[i].first ==2){
            sum[i+1] = matrix_mult(ops[2],sum[i]);
        }
        if(op[i].first ==3){
            ops[3] = {{-1,0,2*op[i].second},{0,1,0},{0,0,1}};
            sum[i+1] = matrix_mult(ops[3],sum[i]);
        }
        if(op[i].first==4){
            ops[4] = {{1,0,0},{0,-1,2*op[i].second},{0,0,1}};
            sum[i+1] = matrix_mult(ops[4],sum[i]);
        }
    }

    for(int i=0;i<Q;i++){
        vector<vector<ll>> mat = {{X[B[i]-1]},{Y[B[i]-1]},{1}};
        auto tmp = matrix_mult(sum[A[i]],mat);
        cout << tmp[0][0] << " " << tmp[1][0] << endl;
    }
}