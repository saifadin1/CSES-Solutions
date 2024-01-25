#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 1e18 
#define int ll
#define mod 1000000007
#define f first
#define s second
#define popcnt __builtin_popcountll
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
int dx[] = {0 , 1 , 0 , -1};
int dy[] = {1 , 0 , -1 , 0};
const int N = 1e6+17;
int n;
 
void solve(){
	cin >> n;
	std::vector<ii> v(n);
	vector<int> flat;
	for(ii &i : v)
		cin >> i.f >> i.s;
 
	for(int i=0; i<n; i++){
		flat.push_back(v[i].f);
		flat.push_back(v[i].s);
	}
	sort(flat.begin(), flat.end());
 	
	// compress
	map<int,int> idx;
	for(int i=0; i<n*2; i++){
		idx[flat[i]] = i;
	}
 
	for(int i=0; i<n; i++){
		v[i].f = idx[v[i].f];
		v[i].s = idx[v[i].s];
	}
 
 
	vector<int> pre(n * 2 + 1);
	for(int i=0; i<n; i++){
		pre[v[i].f] ++;
		pre[v[i].s + 1] --;
	}
 
	for(int i=1; i<2*n; i++){
		pre[i] += pre[i - 1];
	}
 
	int ans = 1;
	for(int i=0; i<2*n; i++){
		chkmax(ans , pre[i]);
	}
 
	cout << ans;
}	
  
main() {
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
   //  freopen("ladder.in", "r", stdin);
	 	// freopen("ladder.out", "w", stdout);  
    int t = 1;
   	//cin >> t;
    
     for (int L = 0; L < t; L++){
       solve();    
     }
} 