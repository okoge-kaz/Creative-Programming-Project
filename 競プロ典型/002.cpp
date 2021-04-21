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
bool judge(string s){
    int n = s.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        if(st.empty()) st.push(s[i]);
        else{
            if(st.top() == '(' && s[i]==')') st.pop();
            else st.push(s[i]);
        }
    }
    return st.empty();
}
int main(){
    int N;
    cin >> N;
    if(N%2==1) cout << endl ;
    else{
        // 偶数でないときは、正しいカッコ列をつくることができないので
        // bit全探索を行う
        vector<string>ans;
        for(int bit=0;bit<(1<<N);bit++){
            string tmp;
            for(int i=0;i<N;i++){
                if( bit & (1 << i)){
                    tmp.push_back('(');
                }
                else{
                    tmp.push_back(')');
                }
            }
            if(judge(tmp)) ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        for(string s:ans) cout << s << endl;
    }
}