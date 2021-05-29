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
    if((int)s.size() <= 3){
        vector<int>vec;
        for(char c:s) vec.push_back(c-'0');
        sort(vec.begin(),vec.end());
        do {
            int tmp = 0;
            for(int v:vec) tmp = tmp * 10 + v;
            if(tmp % 8 == 0){
                cout << "Yes" << endl;
                return 0;
            }
        }while(next_permutation(vec.begin(),vec.end()));
        cout << "No" << endl;
        return 0;
    }
    map<int,int>nums;
    for(char c:s) nums[(c-'0')]++;
    // これで数字と個数に置き換えができた
    bool ok = false;
    for(int a=1;a<=9;a++){
        for(int b=1;b<=9;b++){
            for(int c=1;c<=9;c++){
                int n = a*100 + b*10 + c;
                if(n % 8 == 0){
                    map<int,int>tmp;
                    tmp[a]++, tmp[b]++, tmp[c]++;
                    bool judge = true;
                    for(int i=1;i<=9;i++){
                        if(tmp[i] > nums[i]) judge = false;
                    }
                    if(judge) ok = true;
                }
            }
        }
    }
    ok ? cout << "Yes" << "\n" : cout << "No" << "\n";
}