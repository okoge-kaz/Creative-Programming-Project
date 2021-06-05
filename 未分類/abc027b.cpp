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
    int N; cin >> N;
    vector<int>A(N); for(int &a:A) cin >> a;
    int sum = 0;
    for(int i=0;i<N;i++) sum += A[i];
    if(sum % N != 0){
        cout << -1 << endl;
        return 0;
    }

    vector<int>B(N);// Bが保存する情報は均等にした際の人数と現在の人数の差（何人余るか）
    for(int i=0;i<N;i++){
        B[i] = A[i] - sum/N;
    }

    int ans = 0;
    int tmp = 0;
    int last = 0;
    for(int i=0;i<N;i++){
        tmp += B[i];
        if(tmp == 0){
            tmp = 0;
            ans += (i-last);
            last = i+1;
        }
    }
    if(tmp!=0){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
}