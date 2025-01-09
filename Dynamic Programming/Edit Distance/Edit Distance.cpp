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
 
const int N = 5e3 + 1;
int n , m , dp[N][N];
string s1 , s2;
 
 
void solve(int E){
	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();
	for(int i=0 ;i<=n ;i++){
		dp[i][m] = max(n - i , 0LL);
	}
	for(int i=0 ;i<=m ;i++){
		dp[n][i] = max(m - i , 0LL);
	}
	for(int i=n-1 ;~i ;i--){
		for(int j=m-1 ;~j ;j--){
			if(s1[i] == s2[j]){
				dp[i][j] = dp[i + 1][j + 1];
			} else {
				dp[i][j] = min(dp[i + 1][j + 1] + 1, min(dp[i + 1][j] , dp[i][j + 1]) + 1);
			}
		}
	}
	cout << dp[0][0];
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
