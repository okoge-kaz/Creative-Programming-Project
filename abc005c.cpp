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
    int T, N;
    cin >> T >> N;
    vector<int>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    int M;
    cin >> M;
    vector<int>B(M);
    for(int i=0;i<M;i++) cin >> B[i];
    bool frg = true;
    queue<int>que;
    for(int i=0;i<N;i++) que.push(A[i]);
    for(int i=0;i<M;i++){
        while(!(que.front() >= B[i] - T)){
            que.pop();// 古くなったものを捨てる
            if(que.empty()){
                cout << "no" << endl;
                return 0;
            }
        }
        if(que.front() <= B[i]) que.pop();
        else{
            frg = false;
            break;
        }
        if(i<M-1 && que.empty()){
            cout << "no" << endl;
            return 0;
        } 
    }
    if(frg) cout << "yes" << endl;
    else cout << "no" << endl;
}