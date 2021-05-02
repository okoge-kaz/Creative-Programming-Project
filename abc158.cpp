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
    string s;
    cin >> s;
    deque<int>S;
    for(char c:s) S.push_back(c);
    int Q;
    cin >> Q;
    bool frip = false;
    for(int i=0;i<Q;i++){
        int t;
        cin >> t;
        if(t==1) frip ^= 1;
        else{
            int f;
            cin >> f;
            char c;
            cin >> c;
            if(f==1){
                // fripしていなければ先頭
                if(frip) S.push_back(c);
                else S.push_front(c);
            }
            else{
                if(frip) S.push_front(c);
                else S.push_back(c);
            }
        }
    }
    string ans;
    for(char c:S) ans.push_back(c);
    if(frip) reverse(ans.begin(),ans.end());
    cout << ans << endl;
}