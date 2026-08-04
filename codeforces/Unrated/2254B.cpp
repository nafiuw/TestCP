// Problem: B - Evanescent
// Platform: codeforces
// Contest: Contest-2254
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2254/submission/385562911
// Solved on: 2026-08-04T14:49:30.275Z

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
   int n; string s;
    cin>>n>>s;

    int r = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) r++;
    }
    int b = 0;
    for (int i = 1; i< n-1; i++) {
        if (s[i - 1] != s[i] && s[i] != s[i + 1]) {
            if (s[i - 1] == s[i + 1]) b = max(b, 2);
            else b = max(b, 1);
        }
    }
    cout<<r - b<< '\n';
   
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}