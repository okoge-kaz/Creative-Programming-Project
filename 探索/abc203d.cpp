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

int N,K;
vector<vector<ll>>A;

struct CumulativeSum2D {
    vector<vector<ll>> data;
    bool needToBeBuilt = true;
    // constructer
    CumulativeSum2D(int H, int W) : data(H+1,vector<ll>(W+1,0LL)) {}
    void add(int h, int w, ll z=1){// default arg = 1LL
        // h and w are 0-index
        h++; w++;
        if(h>=(int)data.size() || w>=(int)data[0].size() || h<0 || w<0) assert(0 && "error: index is out of range");
        //枠外アクセスを禁止
        data[h][w]+=z;
    }
    void build(){
        // 計算量 O(HW) 二次元累積和を構築
        for(int i=1;i<(int)data.size();i++) for(int j=1;j<(int)data[0].size();j++){
            data[i][j] += data[i][j-1] + data[i-1][j] - data[i-1][j-1];
        }
        needToBeBuilt = false;
    }
    ll query(int sy, int sx, int gy, int gx){
        // sy,sxは、開始座標点を0-indexで、gy,gxは、1-indexで用いる
        // 正方形としては (sy,sx)が左上、(gy,gx)が右下の範囲の累積和
        if(needToBeBuilt) assert(0 && "error: please call build()");
        return(data[gy][gx] - data[gy][sx] - data[sy][gx] + data[sy][sx]);
    }
};

bool check(ll x){
    // N * N のマス目を生成
    CumulativeSum2D sum(N,N);
    for(int i=0;i<N;i++) for(int j=0;j<N;j++){
        if(A[i][j] >= x) sum.add(i,j);
    }
    // 忘れずに
    sum.build();
    for(int i=0;i<N-K+1;i++) for(int j=0;j<N-K+1;j++){
        if(sum.query(i,j,i+K,j+K) < floor(K*K/2.0) + 1) return false;
        // floor(K*K/2.0) + 1 よりも大きい、すなわち余裕がある
    }
    return true;
}
int main(){
    // input
    cin >> N >> K;
    A.resize(N,vector<ll>(N));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) cin >> A[i][j];
    // Binary Search
    // これは確定ではないが、区間の最小値の場合は二分探索はok=-1とするのがよい
    ll ok = -1; ll ng = INF;
    while(abs(ok-ng)>1){
        ll mid = (ok + ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}