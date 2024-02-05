#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define oo 1e18 + 1 
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

void solve(){
  int n , m;
  cin >> n >> m;
  std::vector<std::vector<int>> adj(n + 1);
  std::vector<int> dp(n + 1) , vis(n + 1) , vis2(n + 1);
  for(int i=0; i<m; i++){
    int u , v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  function<int(int)> dfs = [&](int u){
    vis[u] = vis2[u] = 1;
    dp[u] = u == n;
    for(int v : adj[u]){
      if(!vis[v]) dfs(v);

      dp[u] += dp[v];
      if(dp[u] >= mod) dp[u] -= mod;
    }
    return dp[u];
  };
  for(int i=1; i<=n; i++)
    if(!vis[i]) dfs(i);
  cout << dp[1];
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