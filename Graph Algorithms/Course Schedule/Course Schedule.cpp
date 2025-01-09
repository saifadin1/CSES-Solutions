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
  int n , m;
  cin >> n >> m;
  std::vector<std::vector<int>> graph(n + 1);
  std::vector<int> vis(n + 1);
  std::vector<int> vis2(n + 1);
  for(int i=0; i<m; i++){
    int u , v;
    cin >> u >> v;
    graph[u].push_back(v);
  }
  stack<int>stk;  
  int cnt = 0;
  function<void(int)> dfs = [&](int u){
    vis[u] = vis2[u] = 1; 
    for(int v : graph[u]){
      if(vis2[v]){
        cout << "IMPOSSIBLE";
        exit(0);
      }
      if(!vis[v]) dfs(v);
    }
    vis2[u] = 0;  
    stk.push(u);
  };
  for(int i=1; i<=n; i++)
    if(!vis[i])
      dfs(i);
  while(stk.size()){
    cout << stk.top() << ' ';
    stk.pop();
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