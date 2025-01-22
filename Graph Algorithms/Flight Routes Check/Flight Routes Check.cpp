#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#ifndef ONLINE_JUDGE
// #include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define ii pair<int,int>
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
 
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
 
const int mod = 1e9 + 7 , N = 1e6 + 9;

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Tarjan {
public:
    int n;
    vector<vector<int>> adj;
    vector<int> ids, low;
    vector<bool> onStack;
    stack<int> st;
    int id;
    vector<vector<int>> sccs;

    Tarjan(int n) : n(n), adj(n), ids(n, -1), low(n), onStack(n, false), id(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> findSCCs() {
        for (int i = 0; i < n; i++) {
            if (ids[i] == -1) {
                dfs(i);
            }
        }
        return sccs;
    }

    void dfs(int u) {
        ids[u] = low[u] = id++;
        st.push(u);
        onStack[u] = true;

        for (int v : adj[u]) {
            if (ids[v] == -1) {
                dfs(v);
            }
            if (onStack[v]) {
                low[u] = min(low[u], low[v]);
            }
        }

        if (ids[u] == low[u]) {
            vector<int> scc;
            while (true) {
                int v = st.top();
                st.pop();
                onStack[v] = false;
                scc.push_back(v);
                if (v == u) break;
            }
            sccs.push_back(scc);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Tarjan tarjan(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tarjan.addEdge(u, v);
    }
    vector<vector<int>> sccs = tarjan.findSCCs();
    if (sccs.size() == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        cout << sccs[0][0] + 1 << " " << sccs[1][0] + 1;
    }
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 

 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
} 