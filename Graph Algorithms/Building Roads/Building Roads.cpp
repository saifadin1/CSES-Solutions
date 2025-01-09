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

void sovle(){
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
  function<int()> bfs = [&]{
    queue<int>q;
    q.push(1);
    int ans = 0;
    while(q.size()){
      for(int i=0; i<(int)q.size(); i++){
        int cur = q.front();
        q.pop();
        if(cur == n){
          return ans;
        }
        for(int v : graph[cur]){
          if(!vis[v]){
            vis[v] = 1;
            from[v] = cur;
            q.push(v);
          }
        }
      }
      ans ++;
    }
    return -1LL;
  };
  int ans = bfs();
  if(ans == - 1){
    cout << "IMPOSSIBLE";
  } else {
    std::vector<int> v;
    int cur = n;
    while(cur != 1){
      v.push_back(from[cur]);
      cur = from[cur];
    }
    reverse(v.begin() , v.end());
    cout << v.size() << '\n';
    for(int i : v)
      cout << i << ' ';
  }
}


main() {
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
   //  freopen("ladder.in", "r", stdin);
	 	// freopen("ladder.out", "w", stdout);  
    int t = 1;
  //	cin >> t;

     for (int L = 0; L < t; L++){
     	//cout << "Case " << L + 1 << ": ";
       sovle();    
     }
} 