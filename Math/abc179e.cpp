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
    ll N;
    cin >> N;
    ll X,M;
    cin >> X >> M;
    
    map<ll,ll>excess;
    ll tmp = X;
    ll routinue_length, first_routine_start;
    for(int i=1;i<=M+1;i++){
        if(excess[tmp]>=1){
            routinue_length = i - excess[tmp];
            first_routine_start = excess[tmp];
            break;
        }
        excess[tmp]=i;
        // i+1へ
        tmp = tmp * tmp;
        tmp %= M;
    }

    if(N <= first_routine_start){
        ll a = X;
        ll ans = a;
        for(int i=1;i<N;i++){
            a = a*a;
            a %= M;
            ans += a;
        }
        cout << ans << endl;
    }
    else{
        ll ans = X;
        ll a = X;
        for(int i=1;i<first_routine_start;i++){
            a = a*a;
            a %= M;
            ans += a;
        }
        N -= first_routine_start;
        ll sum_routinue = 0;
        for(int i=0;i<routinue_length;i++){
            a = a*a;
            a %= M;
            sum_routinue += a;
        }
        ans += (N/routinue_length) * sum_routinue;
        for(int i=0;i<N%routinue_length;i++){
            a = a*a;
            a %= M;
            ans += a;
        }
        cout << ans << "\n";
    }
}