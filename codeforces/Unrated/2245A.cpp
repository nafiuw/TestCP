// Problem: A - Who Watches the Watchpig?
// Platform: codeforces
// Contest: Contest-2245
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Pretests passed
// URL: https://codeforces.com/contest/2245/submission/382958820
// Solved on: 2026-07-16T14:50:36.188Z

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
  int n, k;
    cin >> n >> k;
    string s; cin >> s;
    if (n < 2 * k) {
        cout << -1 << "\n";
        return;
    }
    int f = 0;
    for (int i = 0; i < k; ++i) {
        if (s[i] == 'L') {
            f++;
        }
    }
    for (int i = n - k; i < n; ++i) {
        if (s[i] == 'R') {
            f++;
        }
    }
    cout<<f<< "\n";
   
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}