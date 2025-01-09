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
#define mod 1000000007
#define   popcnt  __builtin_popcount	
#define   clr(v, d)  memset(v,d,sizeof(v))
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
const int N = 1e5 + 1;
int n , m , dp[N][101] , ar[N];
 
 
void solve(int E){
	cin >> n >> m;
	for(int i=0 ;i<n ;i++){
		cin >> ar[i];
	}
	if(ar[0] == 0){
		for(int i=1 ;i<=m ;i++) dp[0][i] = 1;
	} else {
		dp[0][ar[0]] = 1;
	}
	for(int i=1 ;i<n ;i++){
		if(ar[i] == 0){
			for(int j=1 ;j<=m ;j++){
				dp[i][j] = dp[i - 1][j];
				if(j + 1 <= m){
					dp[i][j] += dp[i - 1][j + 1];
					dp[i][j] %= mod;
				}
				if(j - 1 >= 1){
					dp[i][j] += dp[i - 1][j - 1];
					dp[i][j] %= mod;
				}
				dp[i][j] %= mod;
			}
		} else {
			dp[i][ar[i]] += dp[i - 1][ar[i]];
			if(ar[i] + 1 <= m){
					dp[i][ar[i]] += dp[i - 1][ar[i] + 1];
					dp[i][ar[i]] %= mod;
				}
				if(ar[i] - 1 >= 1){
					dp[i][ar[i]] += dp[i - 1][ar[i] - 1];
				}
			dp[i][ar[i]] %= mod;
		}
	}
	int ans = 0;
	for(int i=1 ;i<=m ;i++){
		ans += dp[n - 1][i];
		ans %= mod;
	}
	cout << ans;
}
 
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
  cout.tie(0);cout.sync_with_stdio(0);
  //  freopen("snakes.in", "r", stdin);
	 // freopen("snakes.out", "w", stdout);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++) {
		solve(L);
	}	
}
