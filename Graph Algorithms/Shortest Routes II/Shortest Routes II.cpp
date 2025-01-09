#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 1e18 + 1 
#define int ll
#define mod 1000000007
#define f first
#define s second
#define popcnt __builtin_popcountll
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,-1,0,1,1,-1,-1,1};
 
 
const int N = 2e5 + 123;
 
void solve(){
  int n , m , q;
  cin >> n >> m >> q ;
  std::vector<std::vector<int>> dis(n + 1, std::vector<int>(n + 1 , oo));
  for(int i=0; i<m; i++){
    int u , v , w;
    cin >> u >> v >> w;
    chkmin(dis[u][v] , w);
    chkmin(dis[v][u] , w);
  }
  // Floyd Warshall
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      for(int k=1; k<=n; k++)
        if(dis[j][i] != oo &&  dis[i][k] != oo )
          chkmin(dis[j][k] , dis[j][i] + dis[i][k]);
  while(q--){
    int u , v;
    cin >> u >> v;
    if(u == v){
      cout << "0\n";
    } else 
      cout << (min(dis[u][v] , dis[v][u]) >= oo ? -1 : min(dis[v][u] , dis[u][v])) << '\n';
  }
}
 
 
main() {
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
   //  freopen("ladder.in", "r", stdin);
    // freopen("ladder.out", "w", stdout);  
    int t = 1;
  //  cin >> t;
 
     for (int L = 0; L < t; L++){
      //cout << "Case " << L + 1 << ": ";
       solve();    
     }
} 
