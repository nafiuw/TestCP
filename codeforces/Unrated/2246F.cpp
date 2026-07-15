// Problem: F - Whoname and Unsorted Array
// Platform: codeforces
// Contest: Contest-2246
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Accepted
// URL: https://codeforces.com/contest/2246/submission/382823609
// Solved on: 2026-07-15T16:43:58.617Z

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

void op(ve &a, int n, int idx, ve &ans) {
    int x = a[idx], y = a[idx + 1];
    for (int i = idx; i >= 2; i--)
        a[i] = a[i - 1];
    for (int i = idx + 1; i <= n - 1; i++)
        a[i] = a[i + 1];
    a[1] = x;
    a[n] = y;

    ans.PB(idx);
}

void solve() {
    int n; cin >> n;
    ve a(n + 5);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int inv = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j])
                inv++;

    if (n % 2 == 0 && inv % 2) {
        cout << -1 << "\n";
        return;
    }

    if (n == 2) {
        cout << 0 << "\n\n";
        return;
    }
    ve ans;
    int cnt = 0;

    for (int x = n; x >= 3; x--) {
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == x) {
                pos = i;
                break;
            }
        }
        if (pos < n) {
            op(a, n, pos, ans);
        }
        else {
            if (cnt <= 1) {
                op(a, n, 1, ans);
                op(a, n, n - 1, ans);
            }
            else if (cnt == 2) {
                op(a, n, 2, ans);
                op(a, n, 2, ans);
                op(a, n, n - 2, ans);

            }
            else {
                op(a, n, cnt + 1, ans);
                op(a, n, n - 1, ans);
                op(a, n, 1, ans);
            }
        }
        cnt++;
    }

    if (a[n - 1] == 1 && a[n] == 2) {
        if (n == 3) {
            op(a, n, 2, ans);
            op(a, n, 1, ans);

        }
        else {
            op(a, n, n - 3, ans);
            op(a, n, n - 1, ans);
            op(a, n, 1, ans);
            op(a, n, n - 2, ans);
        }
    }
    else {
        if (n == 3) {
            op(a, n, 1, ans);
            op(a, n, 2, ans);
            op(a, n, 1, ans);
        }
        else if (n == 5) {
            op(a, n, 1, ans);
            op(a, n, 2, ans);
            op(a, n, 1, ans);
            op(a, n, 2, ans);
            op(a, n, 1, ans);
        }
        else {
            op(a, n, 1, ans);
            op(a, n, 2, ans);
            op(a, n, 1, ans);
            op(a, n, n - 3, ans);
            op(a, n, 1, ans);
            op(a, n, n - 4, ans);
            for (int i = 1; i <= n - 6; i++)
                op(a, n, 2, ans);

        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x << " ";
    cout << "\n";
}

signed main() {
    fastio

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}