#include <bits/stdc++.h>	
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 1e9 
#define int ll
#define MOD 1000000007
#define   f first
#define   s second
#define   popcnt __builtin_popcountll
#define   clr(v, d) memset(v,d,sizeof(v))
const int N = 2e5 + 9;
 
int n , dp[501][200000];
 
void solve(){
	cin >> n;
	dp[0][0] = 1;
	int sum = n * (n + 1) / 2;
	if(sum & 1) return void(cout << "0");
	sum /= 2;
	for(int i=1 ;i<=n ;i++){
		for(int j=0 ;j<=sum ;j++){
			dp[i][j] = dp[i - 1][j];
			if(j - i >= 0)
				dp[i][j] += dp[i - 1][j - i];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n - 1][sum];
}
 
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
	cout.tie(0);cout.sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++){
		solve();	
	}
}
