#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define oo 1e12
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
 
 
const int N = 2e5 + 123;

int pre[1001][1001] ;

void solve(){
  int n , q;
  cin >> n >> q;
  std::vector<string> g(n);
  for(string& i : g)
    cin >> i;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (g[i - 1][j - 1] == '*');
  while(q--){
    int x1 , y1 , x2 , y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1] << '\n';
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