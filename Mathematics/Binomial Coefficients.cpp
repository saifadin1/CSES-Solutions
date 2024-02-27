#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define oo 1e18
#define int long long
#define mod 1000000007
#define f first
#define s second
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,-1,1};
  

const double pi = 3.14159265359;

const int N = 1e6 + 123;

int Add(int x , int y)
{
  int z = x + y ;
  if(z >= mod)
    z -= mod ;
  return z ;
}
 
int Sub(int x , int y)
{
  int z = x - y ;
  if(z < 0)
    z += mod ;
  return z ;
}
 
int Mul(int x , int y)
{
  return (x * 1ll * y) % mod ;
}
 
int powlog(int base , int power)
{
  if(power == 0)
    return 1 ;
  int x = powlog(base , power / 2) ;
  x = Mul(x , x) ;
  if(power & 1)
    x = Mul(x , base) ;
  return x ;
}
 
int modinv(int x)
{
  return powlog(x , mod-2) ;
}
 
int Div(int x , int y)
{
  return Mul(x , modinv(y)) ;
}
 
struct combination
{
    vector<int>fact , inv ;
    combination(int sz) : fact(sz + 1) , inv(sz + 1)
    {
        fact[0] = 1 ;
        inv[0] = 1 ;
        for(int i = 1 ; i <= sz ; ++i)
            fact[i] = Mul(fact[i-1] , i) ;
        inv[sz] = modinv(fact[sz]) ;
    for(int i = sz-1 ; i >= 1 ; --i)
        inv[i] = Mul(inv[i+1] , i+1) ;
    }
    int choose(int n , int k) const
    {
        if(k < 0 || n < k)
            return 0 ;
        return Mul(Mul(fact[n] , inv[k]) , inv[n - k]) ;
    }
};  

void solve(){ 
  int n;
  cin >> n;
  combination c(N);
  while(n--){
    int a , b;
    cin >> a >> b;
    cout << c.choose(a , b) << '\n';
  }
} 


 
main() {
  
  cin.tie(0);cin.sync_with_stdio(0);
  cout.tie(0);cout.sync_with_stdio(0);
  // freopen("ladder.in", "r", stdin);
  // freopen("ladder.out", "w", stdout);  
  int t = 1;
  //cin >> t;




   for (int L = 0; L < t; L++){
    //cout << "Case " << L + 1 << ": ";
     solve();    
   }
}