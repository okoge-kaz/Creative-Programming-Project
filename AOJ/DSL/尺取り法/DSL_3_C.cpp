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
    int N,Q;
    cin >> N >> Q;
    vector<ll>a(N),x(Q);
    for(int i=0;i<N;i++) cin >> a[i];
    for(int i=0;i<Q;i++) cin >> x[i];

    for(int q=0;q<Q;q++){
        ll crr = 0;
        ll cnt = 0;
        int r = 0;
        for(int l=0;l<N;l++){
            if(crr > x[q]){
                crr -= a[l];
                if(l==r) r++;
                continue;
            }
            while(r < N && crr + a[r] <= x[q]){
                crr += a[r];
                r++;
            }
            cnt += (r-l);
            if(r==l){
                r++;
                continue;//ここ注意
            }
            crr -= a[l];
        }
        cout << cnt << "\n";
    } 
}