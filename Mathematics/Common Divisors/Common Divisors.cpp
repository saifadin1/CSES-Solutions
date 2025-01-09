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
 
const int N = 1e6 + 9;
int ar[N];
 
void solve(int E){
	int n;
	cin >> n;
	for(int i=0 ;i<n ;i++){
		int in;
		cin >> in;
		ar[in]++;
	}
	int ans = 0;
	for(int i=1 ;i<N ;i++){
		int cnt =  0;
		for(int j=i ;j<N ;j+=i){
			cnt += ar[j];
		}
		if(cnt > 1) chkmax(ans , i);
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