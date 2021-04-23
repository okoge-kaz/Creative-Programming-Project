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
    int N;
    cin >> N ;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    int Q;
    cin >> Q;
    vector<ll>B(Q);
    for(int i=0;i<Q;i++) cin >> B[i];

    sort(A.begin(),A.end());
    for(int i=0;i<Q;i++){
        auto itr = lower_bound(A.begin(),A.end(),B[i]);
        if(itr == A.begin()){
            cout << abs(B[i] - A[0]) << endl;
        }
        else{
            int place = itr - A.begin();
            cout << min(abs(B[i]-A[place-1]), abs(B[i]-A[place])) << endl;
        }
    }
}
