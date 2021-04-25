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
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    int cnt = 0;
    for(int q=0;q<Q;q++){
        ll T, A, B;
        cin >> T >> A >> B;
        A--,B--;// 0-index
        if(T==1){
            // O(1)
            if(cnt % 2 == 1){
                if(A >= N) A -= N;
                else if(A < N) A += N;
                if(B >= N) B -= N;
                else B += N;
                char a = S[A], b = S[B];
                S[B] = a, S[A] = b;
                continue;
            }
            char a = S[A], b = S[B];
            S[B] = a, S[A] = b;
        }
        else{
            // 愚直にするとO(N)
            cnt++;
        }
    }
    if(cnt % 2== 1){
        string front  = S.substr(0,N), last = S.substr(N,N);
        S = last + front;
    }
    cout << S << endl;
}