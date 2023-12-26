#include <bits/stdc++.h>	
// #ifndef ONLINE_JUDGE
// #include <deb.h>
// #else
// #define deb(x)
// #endif
using namespace std;
#define ll long long
#define oo 1e18
#define int ll
#define f first
#define s second
#define ii pair<int,int>
#define mod 1000000007
#define   popcnt  __builtin_popcount	
#define   clr(v, d)  memset(v,d,sizeof(v))
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
const int N = 21;
 
int n , m , dp[N][(1 << N)];
std::vector<int> adj[N];
 
void sum(int &a , int b){
	a = ((a % mod) + (b % mod)) % mod;
}
 
void solve(int E){
	cin >> n >> m;
	for(int i=0 ;i<m ;i++){
		int u , v;
		cin >> u >> v;
		u--;v--;
		adj[v].push_back(u);
	}
	dp[0][1] = 1;
	for(int mask=2 ;mask < (1 << n) ;mask++){
		if(!(mask & 1)) continue;
		if(mask != ((1 << n) - 1) && mask & (1 << n - 1)) continue;
		for(int u=0 ;u<n ;u++){
			if(mask & (1 << u)){
				for(int v : adj[u]){
					if(mask & (1 << v)){
						dp[u][mask] += dp[v][mask ^ (1 << u)];
						dp[u][mask] %= mod;
					}
				}
			}
		}
	}
	cout << dp[n - 1][(1 << n) - 1];
}
 
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
  cout.tie(0);cout.sync_with_stdio(0);
  //  freopen("checklist.in", "r", stdin); 
	 // freopen("checklist.out", "w", stdout);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++) {
		solve(L);
	}	
}
