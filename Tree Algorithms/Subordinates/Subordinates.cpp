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
int n;
vector<int> adj[N];
int ans[N];

void dfs(int u , int p){
  for(int v : adj[u]){
    if(v == p) continue;
    dfs(v , u);
    ans[u] += ans[v] + 1;
  }
}

void solve(){
  cin >> n;
  for(int i=2; i<=n; i++){
    int u;
    cin >> u;
    adj[u].push_back(i);
  }  
  dfs(1 , 1);
  for(int i=1; i<=n; i++){
    cout << ans[i] << ' ';
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