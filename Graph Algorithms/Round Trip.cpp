#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 2e9 + 1 
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
  std::vector<int> from(n + 1);
  for(int i=0; i<m; i++){
    int u , v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int now = 1 , x = -1;
  function<int(int , int)> dfs = [&](int u , int p){
    int ret = -1;
    vis[u] = now;
    for(int v : graph[u]){
      if(vis[v] == 0){
        from[v] = u;
        ret = dfs(v , u);
      } else if(v != p){
        if(vis[v] == vis[u]){
          x = u;
          return v;
        }
      }
    }
    return ret;
  };
  for(int i=1; i<=n; i++){
    if(!vis[i]){
      now++;
      int ret = dfs(i , -1);
      if(~ret){
        std::vector<int> v;
        int cur = ret; 
        while(cur != x){
          v.push_back(cur);
          cur = from[cur];
        }
        cout << v.size() + 2 << '\n';
        cout << x << ' '; 
        for(int j : v){
          cout << j << ' ';
        }
        cout << x;
        return;
      }
    }
  }
  cout << "IMPOSSIBLE";
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