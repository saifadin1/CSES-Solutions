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
#define   popcnt __builtin_popcount
#define   clr(v, d) memset(v,d,sizeof(v))
 
int dp[1000009];
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
   cout.tie(0);cout.sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++) {
		int n;
		cin >> n;
		dp[0] = 1;
		for(int i=1 ;i<=n ;i++){
			for(int j=1 ;j<=6 ;j++){
				if(i - j >= 0){
					dp[i] += dp[i - j];
				}
				dp[i] %= MOD;
			}
		}
		cout << dp[n];
	}	
}