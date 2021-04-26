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
vector<ll>LunLun;
void calc(ll d,ll value){
    LunLun.push_back(value);//計算結果を格納
    if(d >= 10) return;// 10桁より上にはいかない

    for(int i=-1;i<=1;i++){
        ll add = (value%10) + i;// 前の桁との差が１
        if(0 <= add && add <= 9) calc(d+1,value*10+add);
    }
}
int main(){
    ll K;
    cin >> K;
    // 具体的にLunLun数であるかどうかを判定することは入力例4から明らかに不可能
    for(int i=1;i<10;i++) calc(1,i);
    sort(LunLun.begin(),LunLun.end());
    cout << LunLun[K-1] << endl;
}