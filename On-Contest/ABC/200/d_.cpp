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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<vector<vector<int>>> b(200);
    int cnt = min(n,8);
    // (1 << 8) = 256 >= 201より
    for(int bit=1;bit<(1<<cnt);bit++){
        // bit = 0とすると、ひとつも選ばないものができてしまう
        int tmp = 0;
        vector<int>tmpv;
        for(int i=0;i<cnt;i++){
            if(bit & (1<<i)){
                tmpv.push_back(i+1);
                tmp += a[i];
                tmp %= 200;
            }
        }
        b[tmp].push_back(tmpv);
    }
    for(auto vec:b){
        if((int)vec.size()>=2){
            cout << "Yes\n";
            cout << (int)vec[0].size() << " ";
            for(int e:vec[0]) cout << e << " ";
            cout << "\n";
            cout << (int)vec[1].size() << " ";
            for(int e:vec[1]) cout << e << " ";
            cout << "\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}