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

// Range Minimum Query and Range Update Query

// copied from Aizu Online Judge EMTHRM (JudgeID: 4899784) 
// 2021-05-15
template <typename T>
struct LazySegmentTree {
  using Monoid = typename T::Monoid;
  using OperatorMonoid = typename T::OperatorMonoid;

  // Constructが２つあるので、渡す引数によってどちらが適応されるかが変わる（オーバーロード）

  LazySegmentTree(int n) : LazySegmentTree(std::vector<Monoid>(n, T::m_unity())) {}

  LazySegmentTree(const std::vector<Monoid> &a) : n(a.size()) {
    while ((1 << height) < n) ++height;
    p2 = 1 << height;// segment treeの長さを決定
    lazy.assign(p2 << 1, T::o_unity());// p2 << 1 = 2 * p2
    dat.assign(p2 << 1, T::m_unity());
    for (int i = 0; i < n; ++i) dat[i + p2] = a[i];// 初期化
    for (int i = p2 - 1; i > 0; --i) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);// 親ノードを更新
  }

  void set(int idx, const Monoid val) {
    idx += p2;// p2 = SEG_LEN
    for (int i = height; i > 0; --i) propagate(idx >> i);
    dat[idx] = val;
    for (int i = 1; i <= height; ++i) {
      int current_idx = idx >> i;
      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx << 1) + 1]);
    }
  }

  void apply(int idx, const OperatorMonoid val) {
    idx += p2;
    for (int i = height; i > 0; --i) propagate(idx >> i);
    dat[idx] = T::apply(dat[idx], val);
    for (int i = 1; i <= height; ++i) {
      int current_idx = idx >> i;
      dat[current_idx] = T::m_merge(dat[current_idx << 1], dat[(current_idx << 1) + 1]);
    }
  }

  void apply(int left, int right, const OperatorMonoid val) {
    if (right <= left) return;
    left += p2;
    right += p2;
    int left_ctz = __builtin_ctz(left);
    for (int i = height; i > left_ctz; --i) propagate(left >> i);
    int right_ctz = __builtin_ctz(right);
    for (int i = height; i > right_ctz; --i) propagate(right >> i);
    for (int l = left, r = right; l < r; l >>= 1, r >>= 1) {
      if (l & 1) sub_apply(l++, val);
      if (r & 1) sub_apply(--r, val);
    }
    for (int i = left >> (left_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
    for (int i = right >> (right_ctz + 1); i > 0; i >>= 1) dat[i] = T::m_merge(dat[i << 1], dat[(i << 1) + 1]);
  }

  Monoid get(int left, int right) {
    if (right <= left) return T::m_unity();
    left += p2;
    right += p2;
    int ctz = __builtin_ctz(left);
    for (int i = height; i > ctz; --i) propagate(left >> i);
    ctz = __builtin_ctz(right);
    for (int i = height; i > ctz; --i) propagate(right >> i);
    Monoid l_res = T::m_unity(), r_res = T::m_unity();
    for (; left < right; left >>= 1, right >>= 1) {
      if (left & 1) l_res = T::m_merge(l_res, dat[left++]);
      if (right & 1) r_res = T::m_merge(dat[--right], r_res);
    }
    return T::m_merge(l_res, r_res);
  }

  Monoid operator[](const int idx) {
    int node = idx + p2;
    for (int i = height; i > 0; --i) propagate(node >> i);
    return dat[node];
  }

private:
  int n, p2, height = 0;
  std::vector<Monoid> dat;
  std::vector<OperatorMonoid> lazy;

  void sub_apply(int idx, const OperatorMonoid &val) {
    dat[idx] = T::apply(dat[idx], val);
    if (idx < p2) lazy[idx] = T::o_merge(lazy[idx], val);
  }

  // propagate = 伝搬させる
  void propagate(int idx) {
    // assert(1 <= idx && idx < p2);
    sub_apply(idx << 1, lazy[idx]);
    sub_apply((idx << 1) + 1, lazy[idx]);
    lazy[idx] = T::o_unity();
  }
};

// 以降は、どのようなクエリなのかで型を定義している

namespace monoid {

    // Range Minimum and Update Query

    template <typename T>
    struct RangeMinimumAndUpdateQuery {
    using Monoid = T;
    using OperatorMonoid = T;
    static constexpr T m_unity() { return std::numeric_limits<T>::max(); }
    static constexpr T o_unity() { return std::numeric_limits<T>::max(); }
    static T m_merge(const T &a, const T &b) { return min(a, b); }
    static T o_merge(const T &a, const T &b) { return b == o_unity() ? a : b; }
    static T apply(const T &a, const T &b) { return b == o_unity()? a : b; }
    };

    // Range Maximum and Update Query

    template <typename T>
    struct RangeMaximumAndUpdateQuery {
    using Monoid = T;
    using OperatorMonoid = T;
    static constexpr T m_unity() { return std::numeric_limits<T>::min(); }
    static constexpr T o_unity() { return std::numeric_limits<T>::min(); }
    static T m_merge(const T &a, const T &b) { return max(a, b); }
    static T o_merge(const T &a, const T &b) { return b == o_unity() ? a : b; }
    static T apply(const T &a, const T &b) { return b == o_unity()? a : b; }
    };

    // Range Minimum and Add Query

    template <typename T, T TINF>
    struct RangeMinimumAndAddQuery {
    using Monoid = T;
    using OperatorMonoid = T;
    static constexpr T m_unity() { return TINF; }
    static constexpr T o_unity() { return 0; }
    static T m_merge(const T &a, const T &b) { return min(a, b); }
    static T o_merge(const T &a, const T &b) { return a + b; }
    static T apply(const T &a, const T &b) { return a + b; }
    };

    // Range Maximum and Add Query

    template <typename T, T TINF>
    struct RangeMaximumAndAddQuery {
    using Monoid = T;
    using OperatorMonoid = T;
    static constexpr T m_unity() { return -TINF; }
    static constexpr T o_unity() { return 0; }
    static T m_merge(const T &a, const T &b) { return max(a, b); }
    static T o_merge(const T &a, const T &b) { return a + b; }
    static T apply(const T &a, const T &b) { return a + b; }
    };

    // Range Sum and Update Query

    template <typename T>
    struct RangeSumAndUpdateQuery {
    struct Node {
        T sum;
        int len;
    };
    static std::vector<Node> init(int n) { return std::vector<Node>(n, Node{0, 1}); }
    using Monoid = Node;
    using OperatorMonoid = T;
    static constexpr Node m_unity() { return {0, 0}; }
    static constexpr T o_unity() { return std::numeric_limits<T>::max(); }
    static Node m_merge(const Node &a, const Node &b) { return Node{a.sum + b.sum, a.len + b.len}; }
    static T o_merge(const T &a, const T &b) { return b == o_unity() ? a : b; }
    static Node apply(const Node &a, const T &b) { return Node{b == o_unity() ? a.sum : b * a.len, a.len}; }
    };

    // Range Sum and Add Query

    template <typename T>
    struct RangeSumAndAddQuery {
    struct Node {
        T sum;
        int len;
    };
    static std::vector<Node> init(int n) { return std::vector<Node>(n, Node{0, 1}); }
    using Monoid = Node;
    using OperatorMonoid = T;
    static constexpr Node m_unity() { return {0, 0}; }
    static constexpr T o_unity() { return 0; }
    static Node m_merge(const Node &a, const Node &b) { return Node{a.sum + b.sum, a.len + b.len}; }
    static T o_merge(const T &a, const T &b) { return a + b; }
    static Node apply(const Node &a, const T &b) { return Node{a.sum + b * a.len, a.len}; }
    };
}  // monoid

int main() {
  int n, q; cin >> n >> q;
  LazySegmentTree<monoid::RangeMinimumAndUpdateQuery<int>> rmq(n);
  while (q--) {
    int query, s, t; cin >> query >> s >> t;
    if (query == 0) {
      int x; cin >> x;
      rmq.apply(s, t + 1, x);
    } else if (query == 1) {
      cout << rmq.get(s, t + 1) << '\n';
    }
  }
  return 0;
}
