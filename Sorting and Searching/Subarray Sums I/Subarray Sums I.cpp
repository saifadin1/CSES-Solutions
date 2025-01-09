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


void solve(){ 
  int n , k;
  cin >> n >> k;
  std::vector<int> v(n);
  for(int& i : v)
    cin >> i;
  int ans = 0 , l = 0 , r = 0 , s = v[0];
  while(r < n){
    if(s == k){
      ans++;
      s -= v[l];
      l++;
      r++;
      if(r < n)
        s += v[r];
    } else if(s > k){
      s -= v[l];
      l++;
    } else {
      r++;
      if(r < n)
        s += v[r];
    }
  }
  cout << (s == k) + ans;
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