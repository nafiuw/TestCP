// Problem: B - KiaKio and Squared Numbers
// Platform: codeforces
// Contest: Contest-2269
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2269/submission/392352548
// Solved on: 2026-09-27T16:22:07.224Z

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


int f(int x) {
    int s = 0;
    while (x) {
        int d = x % 10;
        s += d * d;
        x /= 10;
    }

    return s;
}

int get(int x) {
    static int c[] = {4, 16, 37, 58, 89, 145, 42, 20};
    unordered_map<int, int> vis;
    int t = 0;
    while (!vis.count(x)) {
        vis[x] = t++;
        x = f(x);
    }
    if (x == 1)
        return 0;
    int p = 0;
    while (c[p] != x)
        p++;
    return 1 + (p - vis[x] + 8) % 8;
}

void solve() {
    int n; cin >> n;
    map<int, ll> cnt;
    while (n--) {
        int x;
        cin >> x;
        cnt[get(x)]++;
    }
    ll ans = 0;
    for (auto [x, c] : cnt)
        ans +=c * (c - 1) / 2;
    cout<<ans<<'\n';
}

signed main() {
    fastio

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}