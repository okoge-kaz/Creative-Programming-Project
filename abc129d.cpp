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
int H,W;
vector<string>S;
int main(){
    // input
    cin >> H >> W;
    S.resize(H);
    for(int i=0;i<H;i++) cin >> S[i];
    // ここで前処理が必要になる
    // 解説がとてもわかりやすい https://img.atcoder.jp/abc129/editorial.pdf
    vector<vector<int>>L(H,vector<int>(W));// Left
    vector<vector<int>>R(H,vector<int>(W));// Right
    vector<vector<int>>U(H,vector<int>(W));// Up
    vector<vector<int>>D(H,vector<int>(W));// Down
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(S[h][w]=='#'){
                L[h][w] = 0;
            }
            else{
                if(w==0){
                    L[h][w] = 1;
                }
                else L[h][w] = L[h][w-1] + 1;// 小さいものから更新
            }
        }
    }
    for(int h=0;h<H;h++){
        for(int w=W-1;w>=0;w--){
            if(S[h][w]=='#'){
                R[h][w] = 0;
            }
            else{
                if(w==W-1){
                    R[h][w] = 1;
                }
                else R[h][w] = R[h][w+1] + 1;// 大きいものから更新
            }
        }
    }
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(S[h][w]=='#'){
                U[h][w] = 0;
            }
            else{
                if(h==0){
                    U[h][w] = 1;
                }
                else U[h][w] = U[h-1][w] + 1;// 小さいものから更新
            }
        }
    }
    for(int h=H-1;h>=0;h--){
        for(int w=0;w<W;w++){
            if(S[h][w]=='#'){
                D[h][w] = 0;
            }
            else{
                if(h==H-1){
                    D[h][w] = 1;
                }
                else D[h][w] = D[h+1][w] + 1;
            }
        }
    }
    // 愚直な実装ではO(N^3)なので間に合わない
    // 計算量は、O(N^2 log(N))で解けるはず
    int ans = 0;
    for(int h=0;h<H;h++){
        for(int w=0;w<W;w++){
            if(S[h][w]=='#')continue;
            // O(√N or log(N))で計算しないといけない
            int tmp = L[h][w] + R[h][w] + U[h][w] + D[h][w] - 3;// 過剰に数えている点
            ans = max(ans,tmp);
        }
    }
    cout << ans << endl;
}