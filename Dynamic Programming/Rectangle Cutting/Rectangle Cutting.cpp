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

const int mod = 998244353 , N = 2e5 + 9;

void solve() {
    int n , m;
    cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1 , 1e9));
    // dp[i][j] = min number of moves to cut i * j rectangle into squares
    // try all possible cuts horizontally and vertically
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k=1; k<i; k++) {
                    chkmin(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k=1; k<j; k++) {
                    chkmin(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }

    cout << dp[n][m];
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