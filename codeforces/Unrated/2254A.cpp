// Problem: A - Riptide
// Platform: codeforces
// Contest: Contest-2254
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2254/submission/385554831
// Solved on: 2026-08-04T14:41:19.913Z

// Problem Link:
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avnth
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
   int x, y, z; cin >> x >> y >> z;
    int ans = 0;
    while (x != y && y != z && x != z) {
        int a[3] = {x, y, z};

        int mx = 0, mn = 0;
        for (int i = 1; i < 3; i++) {
            if (a[i] > a[mx]) mx = i;
            if (a[i] < a[mn]) mn = i;
        }
        a[mx]--;
        a[mn]++;
        x = a[0];
        y = a[1];
        z = a[2];
        ans++;
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