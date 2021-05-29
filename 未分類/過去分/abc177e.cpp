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
// 解説：けんちょん https://drken1215.hatenablog.com/entry/2020/10/31/203300
// https://atcoder.jp/contests/abc177/tasks/abc177_e/editorial
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
int main(){
    int N;
    cin >> N;
    vector<ll>A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    vector<ll>nums(1000001);
    for(int i=0;i<N;i++) nums[A[i]]++;
    // これで個数がわかる
    bool coprime = true;
    for(int a=2;a<=1000000;a++){// 素数を考えているので 2から
        // a * a <= 1000000 でもよさそうな気がするが、同じ数 A[i] = A[j] であることがありえるので、このようにしている。
        ll sum = 0;
        for(int b=a;b<=1000000;b+=a) sum += nums[b];
        if( sum > 1) coprime = false;// もしここで1より大きいということは、約数があるということ
    }

    if(coprime){
        cout << "pairwise coprime" << endl;
        return 0;
    }
    
    ll gcd_A = A[0];
    for(int i=0;i<N;i++) gcd_A = GCD(gcd_A,A[i]);
    if(gcd_A == 1LL){
        cout << "setwise coprime" << endl;
        return 0;
    }

    cout << "not coprime" << endl;
}