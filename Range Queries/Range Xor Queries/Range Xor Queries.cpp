#include <bits/stdc++.h>    
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define oo 1e12
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
 
 
const int N = 2e5 + 123;

int ar[N] , tr[1 << 19];

void bld(int x , int l , int r){
  if(l == r){
    tr[x] = ar[l];
    return;
  }
  int md = (l + r) / 2;
  bld(x * 2 + 1 , l , md);
  bld(x * 2 + 2, md + 1 , r);
  tr[x] = tr[x * 2 + 1] ^ tr[x * 2 + 2];
}

int qry(int l , int r , int x , int lx , int rx){
  if(rx < l || lx > r) return 0;
  if(lx >= l && rx <= r){
    return tr[x];
  }
  int md = (lx + rx) / 2;
  return qry(l , r , x * 2 + 1 , lx , md) ^ qry(l , r , x * 2 + 2 , md + 1 , rx);
}

void upd(int i , int v , int x , int lx , int rx){
  if(lx > i || rx < i) return;
  if(lx == rx){
    tr[x] = v;
    return;
  }
  int md = (lx + rx) / 2;
  upd(i , v , x * 2 + 1 , lx , md);
  upd(i , v , x * 2 + 2 , md + 1 , rx);
  tr[x] = min(tr[x * 2 + 1] , tr[x * 2 + 2]);
}

void solve(){
  int n , q;
  cin >> n >> q;
  for(int i=0; i<n; i++){
    cin >> ar[i];
  }
  bld(0 , 0 , n - 1);
  while(q--){
    int l , r;
    cin >> l >> r;
    l--;
    r--;
    cout << qry(l , r , 0 , 0 , n - 1) << '\n';
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