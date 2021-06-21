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
    int N,K; cin >> N >> K;
    string S; cin >> S;
    // 順番を変更していいのであれば簡単だが
    vector<vector<int>>nex(N+1,vector<int>(26));
    for(int i=0;i<26;i++) nex[N][i] = N;
    // 初期値をうめた
    // ここの更新が肝
    for(int i=N-1;i>=0;i--){
        for(int j=0;j<26;j++){
            if((int)(S[i]-'a')==j){
                nex[i][j] = i;
            }
            else nex[i][j] = nex[i+1][j];
        }
    }
    // Greedy
    string ans;
    int curr=0;
    for(int i=1;i<=K;i++){
        for(int j=0;j<26;j++){
            // currより後ろにあるj文字
            int nextpos = nex[curr][j];
            int MaxPossibleLength = (N - (nextpos + 1)) + i;
            if(MaxPossibleLength >= K){
                // Kを超える見込みがない非現実的なものはスルー
                ans += (char)('a'+j);
                curr = nextpos + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}