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

const int N = 2e5 + 123;

std::vector<int> g[N];
set<int> d[N];
int ans[N];

void dfs(int u,  int p){
  for(int v : g[u]){
    if(v == p) continue;
    dfs(v , u);
    if(d[u].size() < d[v].size()) swap(d[u] , d[v]);
    for(auto i : d[v])
      d[u].insert(i);
  }
  ans[u] = d[u].size();
}

void solve(){
  int n;
  cin >> n;
  for(int i=1; i<=n; i++){
    int col;
    cin >> col;
    d[i].insert(col);
  }
  for(int i=0; i<n-1; i++){
    int u , v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1 , 0);
  for(int i=1; i<=n ;i++){
    cout << ans[i] << ' ';
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