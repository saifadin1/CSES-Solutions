#include <bits/stdc++.h>    
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 1e17 
#define int ll
#define mod 1000000007
#define f first
#define s second
#define popcnt __builtin_popcountll
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
// using namespace __gnu_pbds;
// typedef tree<ii,null_type,less<ii>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
 
int dx[] = {1 , 0 , -1 , 0};
int dy[] = {0 , -1 , 0 , 1};
 
 
const int N = 1000500; 
int n , k , comp[N];
void solve(int E){
	int x;
	cin >> x;
	int ans = 1;
	while(x > 1){
		int cur = 0;
		int d = comp[x];
		while(x % d == 0){
			cur++;
			x /= d;
		}
		ans *= cur + 1;
	}
	cout << ans << '\n';
}
 
 
int32_t main() {
	 cin.tie(0);cin.sync_with_stdio(0);
	 cout.tie(0);cout.sync_with_stdio(0);
	 //freopen("sticks.in", "r", stdin);
	 //freopen("output.txt", "w", stdout);  
	 
	 iota(comp , comp + N , 0);
	 for(int i=2 ;i<N/i ;i++)
	 	for(int j=i*i ;j<N ;j+=i)
	 		if(comp[j] == j) comp[j] = i;
 
	 int t = 1;
	 cin >> t;
	  for (int L = 0; L < t; L++){
	    solve(L);  
	  }
}