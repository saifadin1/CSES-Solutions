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
 
const int N = 1e6 + 9; 
int dp[N];
 
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
	cout.tie(0);cout.sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++) {
		int n;
		cin >> n;
		for(int i=1 ;i<=n ;i++)
			dp[i] = oo;
		for(int i=0 ;i<= 9 ;i++)
			dp[i] = 1;
		for(int i=1 ;i<=n ;i++){
			string temp = to_string(i);
			for(int j=0 ;j<temp.size() ;j++)
				dp[i] = min(dp[i] , dp[i - (temp[j] - '0')] + dp[(temp[j] - '0')]);
		}
		cout << dp[n];
	}
}