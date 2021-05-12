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
    ll N, K;
    cin >> N >> K;
    vector<ll>A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    // K番目に小さいとかはほとんど２分探索
    ll ok = INF, ng = -INF;
    while(ok-ng>1){
        ll mid = (ok + ng)/2;
        ll S=0,T=0;
        for(int i=0;i<N;i++){
            if(A[i]>0){
                int l1 = -1,r1 = N;
                while(r1-l1>1){
                    int m = (l1+r1)/2;
                    if(A[i]*A[m] <= mid) l1 = m;
                    else r1 = m;
                }// ここでmid以下となる組み合わせの個数を探している
                S += (l1+1);//0-index
            }
            else if(A[i]<0){
                int l2=-1,r2=N;
                while(r2-l2>1){
                    int m = (r2+l2)/2;
                    if(A[i]*A[m]<=mid) r2 = m;//A[i]<0なので大きい数をかければ必ず A[i]*A[m]<=mid は成立する
                    // よって求めたいのはいつもと逆
                    else l2 = m;
                }
                S += (N-r2);
            }
            else{
                // A[i] == 0のとき
                if(mid >= 0) S+= N;// mid>=0出ない場合は、A[i]*A[k] < 0 となることはありえないので
            }
            if(A[i]*A[i]<=mid) T++;//これはペアではなく、自分自身同士なので
        }
        ll num = (S - T)/2;
        if(num >= K) ok = mid;//多すぎるのでokの範囲を小さくする
        else ng = mid;
    }
    cout << ok << endl;
}