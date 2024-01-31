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
 
struct edge{
  int u , v , w;
  edge(int _u , int _v , int _w){
    u = _u;
    v = _v;
    w = _w;
  }
};
 
void solve(){
  int n , m;
  cin >> n >> m;
  std::vector<edge> edges;
  std::vector<int> dis(n + 1 , oo);
  std::vector<int> from(n + 1);
  bool f = 0;
  int x;
  for(int i=0; i<m; i++){
    int u , v , w;
    cin >> u >> v >> w;
    if(u == v && w < 0) f = 1 , x = u; 
    edges.push_back(edge(u , v , w));
  }
  int ptr = -1;
  // bell-man ford
  for(int i=0; i<n && ptr; i++){
    ptr = 0;
    for(auto j : edges){
        if(chkmin(dis[j.v] , dis[j.u] + j.w))
          from[j.v] = j.u , ptr = j.v;; 
    }
    if(!ptr){
      cout << "NO\n";
      return;
    }
  }

  // if ptr != 0 the must be a neg cycle


  // go back n steps to be sure that ptr are in a cycle 
  for(int i=0; i<n; i++)
    ptr = from[ptr];


  std::vector<int> cyc;
  for(int i=ptr ; ; i=from[i]){
    cyc.push_back(i);
    if(i == ptr && cyc.size() > 1){
      break;
    }
  }
  reverse(cyc.begin() , cyc.end());
  cout << "YES\n";
  for(int i : cyc)
    cout << i << ' ';
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