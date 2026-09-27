// Problem: C - K Is Important
// Platform: codeforces
// Contest: Contest-2269
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2269/submission/392352509
// Solved on: 2026-09-27T16:21:32.036Z

// Problem Link:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avneth
using namespace std;
using namespace __gnu_pbds;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define PB push_back
#define all(x) x.begin(), x.end()

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

const ll mod = 998244354;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;

int n, k;
vector<int> a, bit;

void upd(int i, int v) {
    for (; i <= n; i += i & -i) bit[i] += v;
}
int kth(int k) {
    int pos = 0, b = 1;
    while ((b << 1) <= n) b <<= 1;
    for (; b; b >>= 1) {
        int nx = pos + b;
        if (nx <= n && bit[nx] < k) { pos = nx; k -= bit[nx]; }
    }
    return pos + 1;
}

void solve() {
    cin >> n >> k;
    a.assign(n + 1, 0);
    bit.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(i, 1);
    }
    ll ans = 0;
    int m = n;
    while (m >= k) {
        int l = kth(k);
        int r = kth(m - k + 1);
        int p = (a[l] >= a[r]) ? l : r;
        ans += a[p];
        upd(p, -1);
        m--;
    }
    cout << ans << '\n';
}

signed main() {
    fastio
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}