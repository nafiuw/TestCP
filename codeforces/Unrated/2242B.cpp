// Problem: B - Predominant Frequency Division
// Platform: codeforces
// Contest: Contest-2242
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2242/submission/381463181
// Solved on: 2026-07-06T14:46:13.203Z

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
    int n; cin >> n;
    ve a(n + 1), preA(n + 1), preB(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        preA[i] = preA[i - 1];
        preB[i] = preB[i - 1];
        if (a[i] == 1) {
            preA[i]++;
            preB[i]++;
        }
        else if (a[i] == 2) {
            preA[i]--;
            preB[i]++;
        }
        else {
            preA[i]--;
            preB[i]--;
        }
    }
    int mn = inf;
    for (int j = 2; j <= n - 1; j++) {
        int i = j - 1;
        if (preA[i] >= 0) mn = min(mn,preB[i]);
        if (mn<=preB[j]) {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}