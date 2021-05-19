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
int dt[] = {1,-1,5,-5,10,-10};
int main(){
    int A, B;
    cin >> A >> B;
    int ans = 0;
    vector<vector<bool>> tmp (1000,vector<bool>(1000,false));
    tmp[0][A] = true;
    while(!tmp[ans][B]){
        for(int i=0;i<1000;i++){
            if(tmp[ans][i]){
                for(int j=0;j<6;j++){
                    if(i+dt[j]>=0 && i+dt[j] < 1000){
                        tmp[ans+1][i+dt[j]] = true;
                    }
                }
            }
        }
        ans++;
    }
    cout << ans << endl;
}