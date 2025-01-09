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
#define MOD 1000000007
#define f first
#define s second
#define popcnt __builtin_popcountll
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
 
const int N = 2e5 + 14;
int n , ar[N];
 
void solve(int E){
	cin >> n;
	int lst = -oo , ans = -oo;
	for(int i=0 ;i<n ;i++){
		int in;
		cin >> in;
		if(lst + in < in) lst = in;
		else lst += in;
		chkmax(ans , lst);
	}
	cout << ans;
}
 
 
 
int32_t main() {
	 cin.tie(0);cin.sync_with_stdio(0);
	 cout.tie(0);cout.sync_with_stdio(0);
	 //freopen("sticks.in", "r", stdin);
	 //freopen("output.txt", "w", stdout);  
	 int t = 1;
	 //cin >> t;
	  for (int L = 0; L < t; L++){
	    solve(L);  
	  }
}