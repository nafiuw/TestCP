// Problem: C - MEXOR
// Platform: codeforces
// Contest: Contest-2245
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Pretests passed
// URL: https://codeforces.com/contest/2245/submission/382969192
// Solved on: 2026-07-16T15:08:38.023Z

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

    int n; ll k; cin >> n >> k;
    int B = 0;
    while ((1LL << B) <= n - 1) B++;
    ll kp = k ^ n;
    if (kp >= (1LL << B)) {
        cout << "NO\n";
        return;
    }
    cout<< "YES\n";
    ve f(n);
    int idx = 0;
    int zero = (n - 1) - __builtin_popcountll(kp);
    for (int i = 0; i < zero; i++) {
        f[idx++] = 0;
    }
    for (int i = 0; i <= 30; i++) {
        if ((kp >> i) & 1LL) {
            f[idx++] = (1 << i);
        }
    }
    f[idx++] = n;
    vector<bool> inS(n, true);
    int mx = n - 1;
    ve p(n);
    for (int i = n - 1; i >= 0; i--) {
        int prv = (i == 0 ? 0 : f[i - 1]);

        if (f[i] > prv) {
            p[i] = prv;
            inS[prv] = false;
        }
        else {
            while (!inS[mx]) mx--;
            p[i] = mx;
            inS[mx] = false;
        }
    }
    for (int i = 0; i < n; i++) 
        cout<<p[i]<<" \n"[i == n - 1];
    
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}