// Problem: B - Lady Bug
// Platform: codeforces
// Contest: Contest-2092
// Rating/Difficulty: 1000
// Language: C++23 (GCC 14-64, msys2)
// URL: https://codeforces.com/contest/2092/submission/381317858
// Solved on: 2026-07-05T10:07:17.364Z

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> vv;
vector<bool> vis;
string a, b;
void dfs(int u, vector<int> &comp) {
    vis[u] = true;
    comp.push_back(u);
    for (int v : vv[u]) {
        if (!vis[v]) dfs(v, comp);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin >> a >> b;
 
        vv.assign(2 * n, vector<int>());
        vis.assign(2 * n, false);
 
        for (int i = 1; i < n; i++) {
            int a_i = i;      
            int a_i_1 = i - 1; 
            int b_i = n + i;       
            int b_i_1 = n + i - 1;
 
           
            vv[a_i].push_back(b_i_1);
            vv[b_i_1].push_back(a_i);
 
            vv[b_i].push_back(a_i_1);
            vv[a_i_1].push_back(b_i);
        }
 
        bool flag = true;
 
        for (int i = 0; i < 2 * n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, comp);
 
                int cap = 0;
                int oa = 0, ob = 0;
 
                for (int node : comp) {
                    if (node < n) { 
                        cap++;
                        if (a[node] == '1') oa++;
                    } else { 
                        int idx = node - n;
                        if (b[idx] == '1') ob++;
                    }
                }
                int total = oa + ob;
                int bpos = (int)comp.size() - cap;
 
                if (total > bpos) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}