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

void solve(){
  int n;
  cin >> n;
  multiset<int> s;
  while(n--){
    int x;
    cin >> x;
    auto it = s.upper_bound(x);
    if(it != s.end()){
      s.erase(it);
    }
    s.insert(x);
  }
  cout << s.size();
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