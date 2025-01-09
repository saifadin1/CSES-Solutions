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
int n , k;

void solve(){
	cin >> n >> k;
	map<int,int> mp;
	for(int i=0; i<n; i++){
		int in;
		cin >> in;
		if(mp[k - in]){
			cout << mp[k - in] << ' ' << i+1;
			return;
		}
		mp[in] = i + 1;
	}
	cout << "IMPOSSIBLE";
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
