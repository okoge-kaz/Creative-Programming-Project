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
    deque<char>deq;
    int n = s.size();
    bool frip = false;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(s[i]=='R') frip = !frip;
        else{
            if(deq.empty()){
                if(frip) deq.push_front(c);
                else deq.push_back(c);
            }
            else{
                if(frip){
                    if(deq.front()==c){
                        deq.pop_front();
                    }
                    else{
                        deq.push_front(c);
                    }
                }
                else{
                    if(deq.back()==c){
                        deq.pop_back();
                    }
                    else{
                        deq.push_back(c);
                    }
                }
            }
        }
    }
    string ans;
    for(char c:deq){
        ans.push_back(c);
    }
    if(frip) reverse(ans.begin(),ans.end());
    cout << ans << endl;
}