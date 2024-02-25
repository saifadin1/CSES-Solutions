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
vector<int> adj[N];
int n , x , z , d , ans[N] , vis[N];

void dfs(int u , int s){
  vis[u] = 1;
  if(chkmax(d , s)){
    z = u;
  }
  for(int v : adj[u]){
    if(vis[v]) continue;
    dfs(v , s + 1);
  }
}

void solve(){
  cin >> n;
  for(int i=1; i<n; i++){
    int u , v;
    cin >> u >> v;
    adj[u].push_back(v);S
    adj[v].push_back(u);
  }  
  dfs(1 , 0);
  for(int i=1; i<=n; i++)
    vis[i] = 0;
  x = z;
  d = 0;
  dfs(x , 0);
  cout << d;
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