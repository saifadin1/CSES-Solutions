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
 
const int N = 2e6 + 2;
 
int n , coins[N] , dp[N] , k ;
 
void solve(int E){
	cin >> n >> k;
	for(int i=0 ;i<n ;i++)
		cin >> coins[i];
	for(int i=0 ;i<=k ;i++) dp[i] = oo;
	dp[0] = 0;
	for(int i=1 ;i<=k ;i++){
		for(int j=0 ;j<n ;j++){
			if(i >= coins[j])
			chkmin(dp[i] , dp[i - coins[j]] + 1);
		}
	}
	if(dp[k] == oo){
		cout << "-1\n";
	} else 
	cout << dp[k];
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
