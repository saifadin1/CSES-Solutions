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
 
const int N = 1e5 + 9; 
int p[N] , v[N] , dp[N];
 
int32_t main() {
	cin.tie(0);cin.sync_with_stdio(0);
	cout.tie(0);cout.sync_with_stdio(0);
	int t = 1;
	//cin >> t;
	for (int L = 0; L < t; L++) {
		int n,x;
		cin >> n >> x;
		for(int i=0 ;i<n ;i++)
			cin >> p[i];
		for(int i=0 ;i<n ;i++)
			cin >> v[i];
		for(int j=0 ;j<n ;j++){
			for(int i=x ;i>=1 ;i--){
				if(i < p[j]) continue;
				dp[i] = max(dp[i] , dp[i - p[j]] + v[j]);
			}
		}
		cout << dp[x];
	}
}
