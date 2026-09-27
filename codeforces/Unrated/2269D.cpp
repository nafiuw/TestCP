// Problem: D - What a SauSaGe! It's All Meat
// Platform: codeforces
// Contest: Contest-2269
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2269/submission/392352436
// Solved on: 2026-09-27T16:20:59.558Z

// Problem Link:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avneth
using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ve vector<int>
#define vc vector<char>
#define PB push_back
#define PPB pop_back
#define mp make_pair
#define vll vector<long long>
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define ld long double
#define vld vector<long double>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vpii vector<pair<int, int>>
#define GCD __gcd
#define INT __int128

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

const ll mod = 998244354;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;

const int K = 8;
const int NEG = -1000000;

int m[K] = {0, 3, 5, 6, 9, 10, 12, 15};

struct Node {
    int a[K];
    Node(int x = -1) {
        if (x == -1) {
            for (int i = 0; i < K; i++)
                a[i] = NEG;
            a[0] = 0;
        } else {
            for (int i = 0; i < K; i++)
                a[i] = ((x ^ m[i]) % 3 == 0);
        }
    }
};
Node merge(Node &a, Node &b) {
    Node c;
    for (int d = 0; d < K; d++) {
        c.a[d] = NEG;
        for (int x = 0; x < K; x++)
            c.a[d] = max(c.a[d], a.a[x] + b.a[x ^ d]);
    }
    return c;
}
vector<Node> st;
vector<int> ar;
void build(int p, int l, int r) {
    if (l == r) {
        st[p] = Node(ar[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    st[p] = merge(st[p * 2], st[p * 2 + 1]);
}
void update(int p, int l, int r, int x, int v) {
    if (l == r) {
        st[p] = Node(v);
        return;
    }
    int mid = (l + r) / 2;
    if (x <= mid)
        update(p * 2, l, mid, x, v);
    else
        update(p * 2 + 1, mid + 1, r, x, v);
    st[p] = merge(st[p * 2], st[p * 2 + 1]);
}

void solve() {
    int n, q; cin >> n >> q;
    ar.resize(n);
    for (int &x : ar)      cin >> x;
    st.resize(4 * n + 5);
    build(1, 0, n - 1);
    cout << st[1].a[0];
    while (q--) {
        int p, x;
        cin >> p >> x;   --p;
        ar[p] = x;
        update(1, 0, n - 1, p, x);
        cout << ' ' << st[1].a[0];
    }
    cout << '\n';
}
//cpp
signed main() {
    fastio

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}