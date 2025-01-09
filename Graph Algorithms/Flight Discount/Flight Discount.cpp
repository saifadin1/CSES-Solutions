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
  std::vector<std::vector<ii>> graph1(n + 1) , graph2(n + 1);
  std::vector<int> dis1(n + 1 , oo) , dis2(n + 1 , oo);
  dis1[1] = 0;
  dis2[n] = 0;
  std::vector<array<int, 3>> edges;
  for(int i=0; i<m; i++){
    int u , v , w;
    cin >> u >> v >> w;
    graph1[u].push_back({v , w});
    graph2[v].push_back({u , w});
    edges.push_back({u , v , w});
  }
  function<void(int , std::vector<std::vector<ii>>& , std::vector<int>&)> dij = [&](int s , std::vector<std::vector<ii>>& graph , std::vector<int>& dis){
    priority_queue<ii , std::vector<ii> , greater<ii>> pq;
    pq.push({0 , s});
    while(pq.size()){
      int u = pq.top().s;
      int w = pq.top().f;
      pq.pop();
      if(dis[u] < w) continue;
      for(ii v : graph[u]){
        if(chkmin(dis[v.f] , v.s + dis[u])){
          pq.push({dis[v.f] , v.f});
        }
      }
    }
  };
  dij(1 , graph1 , dis1);
  dij(n , graph2 , dis2);
  int ans = oo;
  for(auto i : edges){
    chkmin(ans , dis1[i[0]] + dis2[i[1]] + i[2] / 2);
  }
  cout << ans;
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
