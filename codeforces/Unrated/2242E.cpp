// Problem: E - Product of Closures
// Platform: codeforces
// Contest: Contest-2242
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2242/submission/381636608
// Solved on: 2026-07-07T17:21:36.896Z

// Problem Link:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avneth
using namespace std;
using namespace __gnu_pbds;
// #pragma GCC optimize("O3")
// #pragma GCC target("sse4")
// #pragma GCC optimize("unroll-loops")

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
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define GCD __gcd
#define INT __int128

#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

const ll mod = 998244354;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;

void solve() {

    auto Print = [&](int x, int y, int n) {
        int a = 32 - __builtin_clz(x);
        int b = 32 - __builtin_clz(y);
        for (int i = 1; i <= n; i++) {
            int t1 = (x >> (((i + a - 1) / a) * a - i)) & 1;
            int t2 = (y >> (((i + b - 1) / b) * b - i)) & 1;
            cout << (t1 & t2);
        }
        cout << '\n';
    };
    int l, r, n;
    cin >> l >> r >> n;
    int a = 31 - __builtin_clz(r);
    int b = 31 - __builtin_clz(l);
    if (a - b >= 2) {
        Print(1 << a, 1 << (a - 1), n);
    }
    else if (a - b == 1) {
        Print(1 << a, l, n);
    }
    else {
        int t = l ^ r;
        int tt = 32 - __builtin_clz(t);
        l >>= tt;
        l <<= tt;
        Print(l, l, n);
    }
}

signed main() {
    fastio

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}