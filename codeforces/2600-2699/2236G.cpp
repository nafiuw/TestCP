// Problem: G - Criterion in Burlandia
// Platform: codeforces
// Contest: Contest-2236
// Rating/Difficulty: 2600
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2236/submission/381317564
// Solved on: 2026-07-05T10:04:04.213Z

// Problem Link: https://codeforces.com/contest/2236/problem/G
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//avneth
using namespace std;
using namespace __gnu_pbds;

// #pragma GCCoptimize("O3")
// #pragma GCCtarget("sse4")
// #pragma GCCoptimize("unroll-loops")

#define ve vector<int>
#define vc vector<char>
#define PB push_back
#define vll vector<long long>
#define ll long long
#define all(x) x.begin(), x.end()
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

struct Gph {
    ve tin, tout, dep;
    vector<vector<pair<int, ll>>> up;
    int tm;
    void dfs(int v, const vector<ve>& g, const ve& a, int p = -1) {
        tin[v] = tm++;
        up[0][v] = {p, a[v]};
        for (int l = 1; l < 20; ++l) {
            if (up[l-1][v].F == -1) {
                up[l][v] = {-1, 0};
                continue;
            }
            up[l][v].F = up[l-1][up[l-1][v].F].F;
            up[l][v].S = up[l-1][up[l-1][v].F].S + up[l-1][v].S;
        }
        for (int u : g[v]) {
            if (u == p) continue;
            dep[u] = dep[v] + 1;
            dfs(u, g, a, v);
        }
        tout[v] = tm;
    }
    Gph(const vector<ve>& g, const ve& a) : tin(g.size()), tout(g.size()), dep(g.size()), up(20, vector<pair<int, ll>>(g.size())) {
        tm = 0;
        dfs(0, g, a);
    }
    bool anc(int p, int v) {
        return tin[p] <= tin[v] && tout[p] >= tout[v];
    }
    int lenV(int u, int v) {
        if (!anc(u, v)) swap(u, v);
        return dep[v] - dep[u] - 1;
    }
    pair<int, ll> LA(int v, int k) {
        if (k <= 0) return {v, 0};
        ll s = 0;
        for (int i = 0; i < 20; ++i) {
            if (k >> i & 1) s += up[i][v].S, v = up[i][v].F;
        }
        return {v, s};
    }
    int lca(int u, int v) {
        if (anc(u, v)) return u;
        for (int l = 19; l >= 0; --l) {
            if (up[l][u].F == -1 || anc(up[l][u].F, v)) continue;
            u = up[l][u].F;
        }
        return up[0][u].F;
    }
    bool lower(int a, int b) {
        return tin[a] < tin[b];
    }
};
ll sum(int r) { return r * 1ll * (r + 1) / 2; }
ll seg(int l, int r) { return sum(r) - sum(l - 1); }

void solve() {
    int n, q; cin >> n >> q;
    ve a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<ve> g(n);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].PB(v);
        g[v].PB(u);
    }
    ve par(n), dep(n);
    auto dfs1 = [&](auto& self, int v, int p = -1) -> void {
        par[v] = p;
        for (int u : g[v]) {
            if (u == p) continue;
            dep[u] = dep[v] + 1;
            self(self, u, v);
        }
    };
    dfs1(dfs1, 0);
    ve cp = par;
    vector<ve> cg(n);
    for (int v = 0; v < n; ++v) {
        ve path;
        while (cp[v] > 0 && a[cp[v]] == 0) {
            path.PB(cp[v]);
            cp[v] = cp[cp[v]];
        }
        for (auto& x : path) cp[x] = cp[v];
        if (a[v] == 0 || !v) continue;
        cg[cp[v]].PB(v);
    }
    ve nxt(n), val(n);
    for (int v = 0; v < n; ++v) {
        if (!a[v]) continue;
        nxt[v] = v;
        int xr = a[v], sm = a[v];
        while (xr == sm && nxt[v] > -1) {
            nxt[v] = cp[nxt[v]];
            if (nxt[v] == -1) break;
            xr ^= a[nxt[v]];
            sm += a[nxt[v]];
        }
    }
    for (int v = 0; v < n; ++v) {
        if (!a[v]) {
            if (!v) nxt[v] = -1;
            else nxt[v] = nxt[cp[v]];
        }
        val[v] = dep[v];
        if (nxt[v] > -1) val[v] -= dep[nxt[v]];
        else val[v]++;
    }
    Gph d(g, val);
    Gph c(cg, val);
    while (q--) {
        int u, v; cin >> u >> v;
        --u, --v;
        if (d.lower(v, u)) swap(u, v);
        int z = d.lca(u, v);
        int cv = (a[v] || !v ? v : cp[v]), cu = (a[u] || !u ? u : cp[u]), cz = (a[z] || !z ? z : cp[z]);
        ll ans = 0;
        ve L, R, Ls = {0}, Rs = {0};
        if (c.dep[cv] > c.dep[cz] + 23) {
            int nt = c.LA(cv, c.dep[cv] - (c.dep[cz] + 23)).F;
            auto [to, sm] = d.LA(v, dep[v] - dep[nt]);
            ans += sm;
            v = to;
        }
        if (c.dep[cu] > c.dep[cz] + 23) {
            int nt = c.LA(cu, c.dep[cu] - (c.dep[cz] + 23)).F;
            auto [to, sm] = d.LA(u, dep[u] - dep[nt]);
            ans += sm;
            u = to;
        }
        while (u != z) {
            int to = cp[u];
            if (d.anc(to, z)) to = z;
            L.PB(u);
            Ls.PB(d.lenV(u, to));
            u = to;
        }
        while (v != z) {
            int to = cp[v];
            if (d.anc(to, z)) to = z;
            R.PB(v);
            Rs.PB(d.lenV(v, to));
            v = to;
        }
        L.PB(z);
        reverse(R.begin(), R.end());
        reverse(Rs.begin(), Rs.end());
        for (auto& x : R) L.PB(x);
        for (auto& x : Rs) Ls.PB(x);
        int j = 0, xr = 0, sm = 0;
        ll cnt = 0;
        for (int i = 0; i < L.size(); ++i) {
            while (j < L.size() && xr == sm) {
                xr ^= a[L[j]];
                sm += a[L[j]];
                cnt += Ls[j] + 1;
                j++;
            }
            if (xr != sm) cnt--;
            ans += seg(cnt - Ls[i], cnt);
            if (xr != sm) cnt++;
            xr ^= a[L[i]];
            sm -= a[L[i]];
            cnt -= Ls[i] + 1;
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}