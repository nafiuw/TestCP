// Problem: D1 - Construct an Array (Easy Version)
// Platform: codeforces
// Contest: Contest-2245
// Language: C++23 (GCC 14-64, msys2)
// Verdict: Pretests passed
// URL: https://codeforces.com/contest/2245/submission/382975056
// Solved on: 2026-07-16T15:21:04.184Z

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

    int n, m; cin >> n >> m;
    vector<ve> O(n + 1, ve(n + 1));
    for (int i = 0; i < m; i++) {
        int o, x, y;
        cin >> o >> x >> y;
        O[x][y] = o;
        O[y][x] = o;
    }
    ve type(n + 1);
    for (int i = 1; i <= n; i++) {
        type[i] = O[i][i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (type[i] == 1 && type[j] == 1 && O[i][j] == 2) {
                cout << "NO\n";
                return;
            }
            if (type[i] == 2 && type[j] == 2 && O[i][j] == 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<vector<pii>> adj(n + 1);
    ve indeg(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (type[i] == 1 && type[j] == 2) {
                if (O[i][j] == 1) {
                    adj[j].PB({i, 0});
                    indeg[i]++;
                } else {
                    adj[i].PB({j, 1});
                    indeg[j]++;
                }
            }
        }
    }
    queue<int> q;
    vll dist(n + 1);
    for (int i = 1; i <= n; i++) {
        dist[i] = (type[i] == 2 ? 1 : 0);
        if (indeg[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto [v, w] : adj[u]) {
            dist[v] = max(dist[v], dist[u] + w);
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    if (cnt != n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << (type[i] == 2 ? -dist[i] : dist[i]) << " \n"[i == n];
    }
}

signed main() {
    fastio

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}