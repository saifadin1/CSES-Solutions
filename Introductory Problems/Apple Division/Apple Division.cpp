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
    int n;
    cin >> n;
    vector<int> v(n);
    int ans = INT_MAX, s = 0;
    for(int &i : v){
        cin >> i;
        s += i;
    }
    for(int k=1; k<(1LL<<n); k++){
        int a = 0;
        for(int i=0; i<n; i++){
            if(k & (1LL<<i)){
                a += v[i];
            }
        }
        int diff = abs(s - 2*a);
        chkmin(ans, diff);
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