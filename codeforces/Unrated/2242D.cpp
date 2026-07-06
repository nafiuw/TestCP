// Problem: D - Two Digit Strings
// Platform: codeforces
// Contest: Contest-2242
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2242/submission/381480060
// Solved on: 2026-07-06T15:11:45.808Z

// Problem Link:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avneth
using namespace std;
using namespace __gnu_pbds;
// #pragma GCCoptimize("O3")
// #pragma GCCtarget("sse4")
// #pragma GCCoptimize("unroll-loops")
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
 
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll mod = 998244354;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const int inf = 1e9;


void solve() {

    string s, t; cin>> s>> t;
    int n = s.size(), m = t.size();
    ve pre1(n + 1), pre2(m + 1);
    for (int i = 0; i < n; i++)
        pre1[i + 1] = (pre1[i] + (s[i] - '0')) % 10;
    for (int i = 0; i < m; i++)
        pre2[i + 1] = (pre2[i] + (t[i] - '0')) % 10;
    const int NEG = -inf;
    ve prv(m + 1), cur(m + 1);
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        cur.assign(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            int now = NEG;
            if (pre1[i] == pre2[j]) {
                now = prv[j - 1] + 1;
            }
            cur[j] = max({now, prv[j], cur[j - 1]});
            if (i == n && j == m && pre1[i] == pre2[j]) {
                ans = prv[j - 1] + 1;
            }
        }
        swap(prv,cur);
    }
    cout<< ans << '\n';
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}