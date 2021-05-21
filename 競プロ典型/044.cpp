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
int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    int shift = 0;
    for(int q=0;q<Q;q++){
        int T,x,y;
        cin >> T >> x >> y;
        x--,y--;
        if(T==1){
            x -= shift; y -= shift;
            x %= N; y %= N;
            while(x < 0) x += N; 
            while(y < 0) y += N;
            swap(A[x],A[y]); 
        }
        else if(T==2){
            shift++;
        }
        else{
            x -= shift; x %= N;
            while(x < 0) x += N;
            cout << A[x] << endl;
        }
    }
}