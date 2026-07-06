// Problem: C - Unstable Elements
// Platform: codeforces
// Contest: Contest-2242
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2242/submission/381470445
// Solved on: 2026-07-06T14:55:34.833Z

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

    int n, k; cin>>n>> k;
    ve fr(n + 1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        fr[x]++;
    }   ve v;
    for (int i = 1; i <= n; i++) {
        if (fr[i]) v.PB(fr[i]);
    }
    sort(all(v));
    ve cnt, occ;
    for (auto x : v) {
        if (cnt.empty()||cnt.back() != x) {
            cnt.PB(x);
            occ.PB(1);
        }
        else {
            occ.back()++;
        }
    }
    int m= cnt.size();
    vll sufCnt(m + 1), sufSum(m + 1);
    for (int i = m - 1; i >= 0; i--) {
        sufCnt[i] = sufCnt[i + 1] + occ[i];
        sufSum[i] = sufSum[i + 1] + 1LL * occ[i] * cnt[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ll num = sufCnt[i];
        ll sum = sufSum[i];
        ll need = k-sum;
        if (need % num) continue;
        ll add = need / num;
        if (add >= 1 - cnt[i]) ans++;
    }
    cout <<ans << '\n';
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}