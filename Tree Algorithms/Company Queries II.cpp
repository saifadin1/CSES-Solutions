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
  
const int N = 2e5 + 9;
int n , a , q ,  b , dp[N][18] , depth[N];
vector<int> adj[N];

void dfs(int u , int par){
  dp[u][0] = par;
  for(int v : adj[u]){
    if(v == par) continue;
    depth[v] = depth[u] + 1;
    dfs(v , u);
  }
}

void calcDP(){
  for(int i=1 ;i<18 ;i++){
    for(int u=1 ;u<=n ;u++){
      if(dp[u][i - 1] == -1) continue;
      dp[u][i] = dp[dp[u][i - 1]][i - 1];
    }
  }
}

int LCA(int u , int v){
  if(depth[u] < depth[v])
    swap(u , v);
  for(int k=17 ;k>=0 ;k--){
    if(depth[u] - (1 << k) >= depth[v]){
      u = dp[u][k];
    }
  }
  if(u == v) return u;
  for(int k=17 ;k>=0 ;k--){
    if(dp[u][k] != dp[v][k]){
      u = dp[u][k];
      v = dp[v][k];
    }
  }
  return dp[u][0];
}

int getAncestor(int u , int k){
  int mask = k;
  for(int i=31; ~i; i--){
    if(((1LL << i) & mask) != 0){
      if(depth[u] < (1LL << i))
        return -1;
      u = dp[u][i];
    }
  }
  return u;
}


void solve(){
  cin >> n >> q;
  for(int i=2; i<=n; i++){
    int u;
    cin >> u;
    adj[u].push_back(i);
    adj[i].push_back(u);
  }  
  dfs(1 , 1);
  calcDP();
  while(q--){
    int u , k;
    cin >> u >> k;
    cout << LCA(u , k) << '\n';
  }

} 
   
main() {
  
  cin.tie(0);cin.sync_with_stdio(0);
  cout.tie(0);cout.sync_with_stdio(0);
  // freopen("ladder.in", "r", stdin);
  // freopen("ladder.out", "w", stdout);  
  int t = 1;
  // cin >> t;
   


   for (int L = 0; L < t; L++){
    //cout << "Case " << L + 1 << ": ";
     solve();    
   }
}