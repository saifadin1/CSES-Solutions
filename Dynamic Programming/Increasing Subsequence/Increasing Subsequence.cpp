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

const int mod = 1e9 + 7 , N = 2e5 + 9;

int mul(int a, int b) {
    return (a * b) % mod;
}

int add(int a, int b) {
    return (a + b) % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1 , vector<int>(2));
    dp[1][0] = dp[1][1] = 1;
    for (int i=2; i<=n; i++) {
        dp[i][1] = mul(2 , dp[i - 1][0]);
        dp[i][1] = add(dp[i][1] , dp[i - 1][1]);
        dp[i][0] = dp[i - 1][1];   
        dp[i][0] = mul(dp[i][0] , 2);
    }

    cout << add(dp[n][0] , dp[n][1]);
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
    cin >> t;
    while (t--) {
        solve();
    }
}   