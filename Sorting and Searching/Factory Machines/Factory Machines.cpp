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
 
void solve() {
    int n , t;
    cin >> n >> t;
    int ar[n];
    for (int i=0; i<n; i++) {
        cin >> ar[i];
    }
    auto valid = [&](int x) {
        int sum = 0;
        for (int i=0; i<n; i++) {
            sum += x / ar[i];
            if (sum >= t) return true;
        }
        return false;
    };
    int l=0, r=1e18, md, ans;
    while(l <= r) {
        md = (l + r) >> 1;
        if (valid(md)) r = (ans = md) - 1;
        else l = md + 1;
    }

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