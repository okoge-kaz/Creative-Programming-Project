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

vector<int>L,R;
ld E(int i, int j){
    int cnt = 0; int all = 0;
    for(int k=L[i];k<=R[i];k++){
        for(int l=L[j];l<=R[j];l++){
            if(k > l) cnt++;
            all++;
        }
    }
    return (ld)cnt/(ld)all;
}
int main(){
    // 転倒数と期待値の融合問題とても教育的
    int N; cin >> N;
    L.resize(N); R.resize(N); for(int i=0;i<N;i++) cin >> L[i] >> R[i];
    cout << std::fixed << std::setprecision(15) ;

    ld ans = 0;
    // 本文では100^4でも間に合うので、転倒数はBITを用いていない
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            ans += E(i,j);
        }
    }
    cout << ans << endl;
}