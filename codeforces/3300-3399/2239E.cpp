// Problem: E - The end of this world,
// Platform: codeforces
// Contest: Contest-2239
// Rating/Difficulty: 3300
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2239/submission/382002610
// Solved on: 2026-07-10T16:05:38.920Z

// Problem Link: https://codeforces.com/contest/2239/problem/E
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

const int N = 500500;
const int Q = 2000100;

int n, m;

int a[N];
int A[N];
int B[N];
int l[N];
int w[N];
ve G; ve seg[4 * N];
int L[Q];
int R[Q];
int best[Q];
int res[Q];
ve rem; ve mem;
struct DSURollback {

    ve p; ve sz; ve top;
    vector<pair<int*, int>> his;
    DSURollback(int n) {
        p.resize(n);
        sz.assign(n, 1);
        top.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            top[i] = i;
        }
    }

    int Find(int x) {
        if (p[x] == x) return x;
        return Find(p[x]);
    }

    bool Unite(int u, int v, int t) {

        u = Find(u); v = Find(v);
        if (u == v) return false;
        if (sz[u] > sz[v]) swap(u, v);
        his.PB({&p[u], p[u]});
        his.PB({&sz[v], sz[v]});
        his.PB({&top[v], top[v]});
        p[u] = v;
        sz[v] += sz[u];
        top[v] = t;
        return true;
    }

    void Rollback(int checkpoint) {
        while ((int)his.size() > checkpoint) {
            *his.back().F = his.back().S;
            his.PPB();
        }
    }
};

DSURollback dsu(Q);
int NewNode() {
    int x = rem.back();
    rem.PPB();
    return x;
}

void Merge(int x, int y, int h) {

    x = dsu.top[dsu.Find(x)];
    y = dsu.top[dsu.Find(y)];
    if (x == y) return;
    int z = NewNode();
    best[z] = max(best[x], best[y]);
    res[z] = best[z] + h;
    L[z] = x; R[z] = y;
    dsu.Unite(x, z, z);
    dsu.Unite(y, z, z);
    mem.PB(z);
}

void Undo(int checkpoint) {

    while ((int)mem.size() > checkpoint) {
        int z = mem.back();
        mem.PPB();
        rem.PB(z);
        int x = L[z];
        int y = R[z];
        best[x] = max(best[x], best[z]);
        best[y] = max(best[y], best[z]);
        res[x] = max(res[x], res[z]);
        res[y] = max(res[y], res[z]);
    }
}

void Update(int node, int l, int r, int ql, int qr, int id) {

    if (ql > qr) return;
    if (l == ql && r == qr) {
        seg[node].PB(id);
        return;
    }
    int mid = (l + r) >> 1;
    Update(node << 1, l, mid, ql, min(mid, qr), id);
    Update(node << 1 | 1, mid + 1, r, max(mid + 1, ql), qr, id);
}

void DFS(int node, int l, int r) {

    int memCheckpoint = mem.size();
    int dsuCheckpoint = dsu.his.size();
    for (auto id : seg[node]) {
        Merge(A[id], B[id], G[r]);
    }
    if (l != r) {
        int mid = (l + r) >> 1;
        DFS(node << 1 | 1, mid + 1, r);
        DFS(node << 1, l, mid);
    }
    Undo(memCheckpoint);
    dsu.Rollback(dsuCheckpoint);
}


void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    if (m == 0) {
        for (int i = 1; i <= n; i++) {
            cout << -1 << " ";
        }
        cout << "\n";
        return;
    }
    rem.clear(); mem.clear(); G.clear();
    for (int i = 1; i <= 4 * n; i++) {
        res[i] = -1;
        best[i] = -1;
        if (i > n) rem.PB(i);
    }
    for (int i = 1; i <= n; i++) {
        best[i] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> A[i] >> B[i] >> w[i] >> l[i];
        G.PB(w[i]);
    }
    sort(all(G));
    G.erase(unique(all(G)), G.end());
    for (int i = 0; i <= 4 * (int)G.size(); i++) {
        seg[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int L = lower_bound(all(G), l[i]) - G.begin();
        int R = lower_bound(all(G), w[i]) - G.begin();
        Update(1, 0, (int)G.size() - 1, L, R, i);
    }
    DFS(1, 0, (int)G.size() - 1);
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
    }
}

signed main() {
    fastio

    int t; cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}