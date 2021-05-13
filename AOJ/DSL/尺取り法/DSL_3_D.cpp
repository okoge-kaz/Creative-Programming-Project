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
    int N,L;
    cin >> N >> L;
    vector<int>a(N);
    for(int i=0;i<N;i++) cin >> a[i];
    set<int>st;
    map<int,int>nums;
    if(N > L){
        for(int i=0;i<L-1;i++) st.insert(a[i]), nums[a[i]]++;
        int l=0;
        for(int r=L-1;r<N;r++){
            st.insert(a[r]);
            nums[a[r]]++;
            if(r==N-1){
                cout << *st.begin() << endl;
                return 0;
            }
            cout << *st.begin()<< " ";
            if(nums[a[l]]==1) st.erase(a[l]);
            nums[a[l]]--;
            l++;
        }
    }
    else{
        int ans = inf;
        for(int i=0;i<N;i++) chmin(ans,a[i]);
        cout << ans << "\n";
    }
}