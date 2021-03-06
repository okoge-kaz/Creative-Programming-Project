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
    ll N,M;
    cin >> N >> M;
    vector<ll>a(N),b(N);
    for(int i=0;i<N;i++) cin >> a[i] >> b[i];
    vector<pair<ll,ll>>event;
    for(int i=0;i<N;i++){
        event.push_back(make_pair(a[i],1));
        event.push_back(make_pair(b[i],-1));
    }
    sort(event.begin(),event.end());
    ll crr = 0;
    for(auto[time,value]:event){
        crr += value;
        if(crr > M){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
}