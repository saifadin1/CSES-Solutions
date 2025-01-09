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
 
const int N = 1e6 + 1;
 
int n , dp[101][N];
 
void solve(int E){
	cin >> n;
	std::vector<int> c(n);
	for(int &i : c)
		cin >> i;
	dp[0][0] = 1;
	dp[0][c[0]] = 1;
	for(int i=0 ;i<n ;i++) dp[i][0] = 1;
	for(int x=1 ;x<=100000 ;x++){
		for(int i=1 ;i<=n ;i++){
			dp[i][x] += dp[i - 1][x];
			if(x - c[i] >= 0)
			dp[i][x] += dp[i - 1][x - c[i]];
		}
	}
	std::vector<int> ans;
	for(int x=1 ;x<=100000 ;x++){
		for(int i=1 ;i<=n ;i++){
			if(dp[i][x]){
				ans.push_back(x);
				break;
			}
		}
	}
	cout << ans.size() << '\n';
	for(int i : ans)
		cout << i << ' ';
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
