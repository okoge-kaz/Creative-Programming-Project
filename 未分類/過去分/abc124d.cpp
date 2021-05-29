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
    int N, K; cin >> N >> K;
    string S; cin >> S;
    // 0が連続する区間と、１が連続する区間でうまく分けることが重要
    vector<int> seg;    
    if (S[0] == '0') seg.push_back(0); // 先頭が 0 だったら
    for (int i = 0; i <(int) S.size();) {
        // 尺取り法をwhile文を使わずに書いている
        int j = i;
        while (j < (int)S.size() && S[j] == S[i]) ++j; // S[i] の数値がどこまで続くか
        seg.push_back(j - i);
        i = j;
    }
    if (S.back() == '0') seg.push_back(0); // 最後尾が 0 だったら

    // 累積和
    vector<int> sums((int)seg.size() + 1, 0);
    for (int i = 0; i < seg.size(); ++i) sums[i+1] = sums[i] + seg[i];

    // 偶数番目の添字から始まる、長さ 2K+1 (以下) の区間の総和のうち、最大値を求める
    int res = 0;
    for (int left = 0; left < sums.size(); left += 2) {
        int right = left + K*2+1;
        if (right >= sums.size()) right = (int)sums.size() - 1;
        res = max(res, sums[right] - sums[left]);
    }
    cout << res << endl;
}