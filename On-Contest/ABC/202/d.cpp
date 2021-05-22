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
// 階乗を計算する関数
ll f(ll a, ll b){
    ll res = 1LL;
    ll j=1LL;
    for(ll i = a+b;i>max(a,b);i--){
        res *= i;
        if(j<=min(a,b)) res /= j;
        j++;
    }
    for(ll k=j;k<=min(a,b);k++) res /= k;
    return res;
}
int main(){
    ll A,B,K;
    cin >> A >> B >> K;
    string ans = "";
    int a=0; int b=0;
    // 絶対もっと綺麗な書き方がある。
    while(K){
        if(a==A && b== B) break;
        if(K > f(max(A-a-1,0LL),B-b) && b+1 <= B){
            K -= f(A-a-1,B-b);
            ans.push_back('b');
            b++;
        }
        else if(a==A && K > 0){
            while((ll)ans.size()<(A+B)){
                ans.push_back('b');
            }
            break;
        } 
        else{
            ans.push_back('a');
            a++;
        }
    }
    cout << ans << endl;
    
}