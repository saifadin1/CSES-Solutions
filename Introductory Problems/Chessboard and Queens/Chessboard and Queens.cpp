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
  
int solve(int i, vector<string> &v) {
    if (i == 8) {
        return 1;
    }
    int ans = 0;
    for (int j=0; j<8; j++) {
        bool ok = true;
        if (v[i][j] == '*') {
            ok = false;
        }
        for (int k=0; k<i; k++) {
            if (v[k][j] == 'Q') {
                ok = false;
            }
        }
        for (int k=i, l=j; ~k && ~l; k--, l--) {
            if (v[k][l] == 'Q') {
                ok = false;
            }
        }
        for (int k=i, l=j; ~k && l<8; k--, l++) {
            if (v[k][l] == 'Q') {
                ok = false;
            }
        }
        if (ok) {
            v[i][j] = 'Q';
            ans += solve(i+1,v);
            v[i][j] = '.';
        }
    }

    return ans;
}

void solve() {
    vector<string> v(8);
    for(auto &i : v)
        cin >> i;
    cout << solve(0,v);
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