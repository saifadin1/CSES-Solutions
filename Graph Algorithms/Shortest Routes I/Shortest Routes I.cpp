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
  std::vector<std::vector<ii>> graph(n + 1);
  std::vector<int> vis(n + 1);
  std::vector<int> dis(n + 1 , oo);
  for(int i=0; i<m; i++){
    int u , v , w;
    cin >> u >> v >> w;
    graph[u].push_back({v , w});
  }
  priority_queue<ii , vector<ii> , greater<ii>> pq;
  pq.push({0 , 1});
  dis[1] = 0;
  while(pq.size()){
    int w = pq.top().f;
    int u = pq.top().s; 
    pq.pop();
    if(w > dis[u]) continue;
    for(ii v : graph[u]){
      if(w + v.s < dis[v.f]){
        dis[v.f] = w + v.s;
        pq.push({dis[v.f] , v.f});
      }
    }
  }
  for(int i=1; i<=n; i++){
    cout << dis[i] << ' ';
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