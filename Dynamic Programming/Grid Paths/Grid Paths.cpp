#include <bits/stdc++.h>	
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 1e9
//#define int ll
#define MOD 1000000007
#define   popcnt __builtin_popcount
#define   clr(v, d) memset(v,d,sizeof(v))
 
const int N = 1e3 + 100; 
ll dp[N][N];
 
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
	cout.tie(0);cout.sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++) {
		int n,m;
		cin >> n;
		m = n;
		char g[n][m];
		for(int i=0 ;i<n ; i++)
			for(int j=0 ;j<m ; j++)
				cin >> g[i][j];
		
		dp[n - 1][m - 1] = (g[n - 1][m - 1] != '*');
		for(int i=n - 1 ;i>=0 ;i--)
			for(int j=m - 1 ;j>=0 ;j--){
				if(g[i][j] == '*' || (i == n - 1 && j == m - 1)) continue;
				dp[i][j] = ((dp[i+1][j] % MOD) + (dp[i][j+1] % MOD)) % MOD;
			}
		cout << dp[0][0];
	}
}
