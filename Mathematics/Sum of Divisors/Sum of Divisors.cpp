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
 
int n;
 
ll exp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b & 1)res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}
 
int mul(int a, int b){
	return ((a % mod) * (b % mod)) % mod;
}
 
int inverse(int a){
	return exp(a , mod-2 , mod);
}
 
int sum(int a , int b){
	return mul((b - a + 1) , mul(((a + b)) , inverse(2)));
}
 
 
void solve(int z){   
   cin >> n;
   int ans = 0;
   int r;
   for(int l=1 ;l<=n ;l = r){
   	 int x = n / l;
   	 r = n / x + 1;
   	 ans += mul(sum(l , r - 1) , x);
   	 if(ans > mod) ans -= mod;
   }
   cout << ans ;
}
  
int32_t main() {
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
    //freopen("orxor.in", "r", stdin);
    // freopen("output.txt", "w", stdout);  
    int t = 1;
    //cin >> t;
     for (int L = 0; L < t; L++){
       solve(L);    
     }
}