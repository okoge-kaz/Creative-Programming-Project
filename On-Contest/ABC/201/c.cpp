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
    string s;
    cin >> s;
    int cnt = 0;
    for(int i=0;i<=9999;i++){
        bool ok = true;
        int now = i;
        int x[4];//この書き方はうまい
        for(int k=0;k<4;k++){
            x[k] = now % 10;
            now /= 10;
            // 0-division error は、0で割った時なので、大丈夫
        }
        for(int j=0;j<10;j++){
            if(s[j]=='o' && (x[0]!=j && x[1]!=j && x[2]!=j && x[3]!=j )) ok = false;
            if(s[j]=='x' && (x[0]==j || x[1]==j || x[2]==j || x[3]==j )) ok = false;
        }
        if(ok) cnt++;
    }
    cout << cnt << endl;
}