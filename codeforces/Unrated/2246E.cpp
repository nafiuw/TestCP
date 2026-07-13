// Problem: E. lce4113 and Security Game
// Platform: codeforces
// Language: C++17
// URL: https://codeforces.com/contest/2246/problem/E
// Solved on: 2026-07-13T17:29:23.860Z

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void ask(ll x) {
    cout << x << '\n';
    cout.flush();
}

void ask(ll x, ll y) {
    cout << x << " " << y << '\n';
    cout.flush();
}

void solve() {

    ask(1);
    ll o; cin >> o;
    if (o == -1) exit(0);
    if (o != 1) {
        if ((o & 1) == 0) {
            ask(0, 1);
            ll r;
            cin >> r;
            if (r == -1) exit(0);
            ask(r & 1);
        }
        else {
            int b = 1;
            for (; b < 30; b++) {
                if (o & (1LL << b)) break;
            }
            ask(1LL << b, 0);
            ll r;          cin >> r;
            if (r == -1) exit(0);
            if (r & (1LL << b))
                ask(1);
            else
                ask(0);
        }
        return;
    }
    ll a = 2LL * (rng() % (1 << 29)) + 1;
    ll b = 2LL * (rng() % (1 << 29));
    ask(a, b);

    ll r;
    cin >> r;
    if (r == -1) exit(0);
    if ((r >> 1) == (a >> 1))
        ask(0);
    else if ((r >> 1) == (b >> 1))
        ask(1);
    else
        ask(r & 1);
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}