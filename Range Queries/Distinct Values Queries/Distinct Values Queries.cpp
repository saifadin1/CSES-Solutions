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

const int N = 2e5 + 8;
const int M = 2e5 + 2;
int sqr = 450;
 
struct query {
   int l , r , idx , block_idx;
   query(){}
   query(int _l , int _r , int _idx , int _block_idx){
      l = _l; r = _r; idx = _idx; block_idx = _block_idx;
   }
   bool operator < (const query &b) const {
      if(block_idx == b.block_idx){
         return r < b.r;
      }
      return block_idx < b.block_idx;
   }
};
 
int now , n , q , k , ar[M] , qu_ans[N] , cnt[1000006];
query qu[N];
 
void add(int x){
  cnt[ar[x]]++;
  if(cnt[ar[x]] == 1) now ++; 
}
 
void remove(int x){
  cnt[ar[x]]--;
  if(cnt[ar[x]] == 0) now --;
}
 
void go(){  
   int curL = 2, curR = 1; 
   for (int i = 1; i <= q; i++) {
    while (curR < qu[i].r) add(++curR);
    while (curR > qu[i].r) remove(curR--);
    while (curL < qu[i].l) remove(curL++);
    while (curL > qu[i].l) add(--curL);
    qu_ans[qu[i].idx] = now;
  }
}

void solve(){
  cin >> n >> q;
  for(int i=1; i<=n; i++)
    cin >> ar[i];
  map<int,int> mp;
  int cur = 0;
  for(int i=1; i<=n; i++){
    if(mp[ar[i]] == 0){
      mp[ar[i]] = ++cur;
    }
  }
  for(int i=1; i<=n; i++)
    ar[i] = mp[ar[i]];
  for(int i=1; i<=q; i++){
    int l , r;
    cin >> l >> r;
    qu[i] = query(l , r , i , l / sqr);
  }
  sort(qu + 1 , qu + q + 1);
  go();
  for(int i=1; i<=q; i++){
    cout << qu_ans[i] << '\n';
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