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
 
 
const int N = 2e6 + 123;


void solve(){
  int n , m , k;
  cin >> n >> m >> k;
  std::vector<std::vector<ii>> graph(n + 1);
  std::vector<int> vis(n + 1);
  for(int i=0; i<m; i++){
    int u , v , w;  
    cin >> u >> v >> w;
    graph[u].push_back({v , w});
  }
  priority_queue<ii , std::vector<ii> , greater<ii>>pq;
  pq.push({0 , 1});
  while(pq.size() && vis[n] < k){
    int u = pq.top().s;
    int w = pq.top().f;
    pq.pop();
    vis[u]++;
    if(u == n) cout << w << ' ';
    if(vis[u] <= k){
      for(ii v : graph[u]){
        pq.push({w + v.s , v.f});
      }
    }
  }
}
 
 
main() {
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
   //  freopen("ladder.in", "r", stdin);
    // freopen("ladder.out", "w", stdout);  
    int t = 1;
    //cin >> t;
 
     for (int L = 0; L < t; L++){
      //cout << "Case " << L + 1 << ": ";
       solve();    
     }
}