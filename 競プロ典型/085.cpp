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
    ll K; cin >> K;
    vector<ll>vec;
    for(ll i=1;i*i<=K;i++){
        if( K%i ==0LL){
            vec.push_back(i); 
            if(K/i != i)vec.push_back(K/i);// なんでこれいるの?
        }
    }
    sort(vec.begin(),vec.end());//これ重要
    ll cnt = 0;
    for(int i=0;i<(int)vec.size();i++){
        for(int j=i;j<(int)vec.size();j++){// j = iもはまりどころ
            ll a = vec[i]; ll b = vec[j];
            if((K/a) < b) continue;
            if(K % (a*b)!= 0LL) continue;
            ll c = K / (a*b);
            if(b <= c) cnt++;
        }
    }
    cout << cnt << endl;
}