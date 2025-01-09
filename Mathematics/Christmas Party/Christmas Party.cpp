#include <bits/stdc++.h> 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>   
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define oo 1e17; 
#define int long long
#define mod 1000000007
#define f first
#define s second
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

// using namespace __gcdnu_pbds;
// typedef tree<ii,null_type,less<ii>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,-1,1}; 
 
const int N = 2e6 + 123;

//int f[N] , inv[N];

int mul(int a , int b){
  return ((a % mod) * (b % mod)) % mod;
}

int exp(int a , int p){
  if(p == 0) 
    return 1;
  int x = exp(a , p / 2);
  x = mul(x , x);
  if(p & 1) 
    x = mul(x , a);
  return x;
}


// int choose(int n , int k){
//   return mul(mul(f[n] , inv[k]) , inv[n - k]); 
// }


// Derangements 


int dp[N];

int f(int n){
  if(dp[n] != -1) return dp[n];
  if(n == 1) 
    return 0;
  if(n == 2)
    return 1;
  return dp[n] = mul((n - 1) , (f(n - 2) + f(n - 1)));
}

void solve(){
  clr(dp , -1);
  int n;
  cin >> n;
  cout << f(n);
}
 
 
main() {
  cin.tie(0);cin.sync_with_stdio(0);
  cout.tie(0);cout.sync_with_stdio(0);
 //  freopen("ladder.in", "r", stdin);
  // freopen("ladder.out", "w", stdout);  
  int t = 1;
  //cin >> t;

  // inv[0] = f[0] = 1;
  // for(int i=1; i<N; i++){
  //   f[i] = mul(f[i - 1] , i);
  //   inv[i] = exp(f[i] , mod - 2);
  // }

   for (int L = 0; L < t; L++){
    //cout << "Case " << L + 1 << ": ";
     solve();    
   }
}

