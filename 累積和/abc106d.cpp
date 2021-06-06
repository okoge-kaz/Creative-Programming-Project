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
        // 正方形としては (sy,sx)が左上、(gy,gx)が右下の範囲の累積和
        // sy,sxは、開始座標点を0-indexで、gy,gxは、1-indexで用いる
        if(needToBeBuilt) assert(0 && "error: please call build()");
        return(data[gy][gx] - data[gy][sx] - data[sy][gx] + data[sy][sx]);
    }
};
int main(){
    int N,M,Q; cin >> N >> M >> Q;
    vector<int>L(M), R(M);
    for(int i=0;i<M;i++) cin >> L[i] >> R[i];
    vector<pair<int,int>>query(Q);
    for(int i=0;i<Q;i++) cin >> query[i].first >> query[i].second;

    // 1次元累積和ばかり考えていて、２次元累積和を使うという発想に全く至らなかった
    CumulativeSum2D sum(N,N);
    for(int i=0;i<M;i++){
        sum.add(L[i]-1,R[i]-1);
    }
    sum.build();
    for(int i=0;i<Q;i++){
        cout << sum.query(query[i].first-1,query[i].first-1,query[i].second,query[i].second) << endl;
    }
}