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

class DSU {
public:
    std::vector<int> parent;
    std::vector<int> rank;
    int maxRank = 1;
    int groups = 0;

    DSU(int n) {
        groups = n;
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                parent[rootY] = rootX;
                rank[rootX] += rank[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                rank[rootY] += rank[rootX];
                parent[rootX] = rootY;
            }
            chkmax(maxRank, max(rank[rootX], rank[rootY]));
            groups--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &e) const {
        return w < e.w;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<Edge> edges;
    for (int i=0; i<m; i++) {
        int u , v , w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back(Edge(u, v, w));
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto &e : edges) {
        if (!dsu.connected(e.u, e.v)) {
            dsu.unite(e.u, e.v);
            ans += e.w;
        }
    }
    if (dsu.groups > 1) {
        cout << "IMPOSSIBLE";
    } else 
        cout << ans;
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