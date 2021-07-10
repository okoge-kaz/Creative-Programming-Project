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
using lll = __int128_t;
bool is_prime(ll num){
    if(num==1) return false;
    for(ll i=2;i*i<=num;++i){
        if(num%i==0) return false;
    }
    return true;
}
int main(){
    int N; cin >> N;
    vector<int>primes;
    for(int i=2;i<=55555;i++){
        if(is_prime(i)) primes.push_back(i);
    }
    // 5つ選ぶというところから、mod 5について着目すべし
    vector<int>vec1,vec2,vec3,vec4;
    for(int e:primes){
        if(e%5==1) vec1.push_back(e);
    }
    for(int e:primes){
        if(e%5==2) vec1.push_back(e);
    }
    for(int e:primes){
        if(e%5==3) vec1.push_back(e);
    }
    for(int e:primes){
        if(e%5==4) vec1.push_back(e);
    }
    //
    vector<int>ans;
    if((int)vec1.size()>=N){
        for(int i=0;i<N;i++) ans.push_back(vec1[i]);
    }
    else if((int)vec2.size()>=N){
        for(int i=0;i<N;i++) ans.push_back(vec2[i]);
    }
    else if((int)vec3.size()>=N){
        for(int i=0;i<N;i++) ans.push_back(vec3[i]);
    }
    else if((int)vec4.size()>=N){
        for(int i=0;i<N;i++) ans.push_back(vec4[i]);
    }
    //
    for(int e:ans) cout << e << " ";
    cout << endl;
}