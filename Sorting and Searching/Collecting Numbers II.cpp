#include <bits/stdc++.h>  
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif  
using namespace std;
#define int long long
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}


main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);  

  int n , q;
  cin >> n >> q;
  std::vector<int> idx(n + 2) , who(n + 1);
  idx[n + 1] = n + 1;
  int ans = 0;
  for(int i=1 , x; i<=n; i++){
    cin >> x;
    idx[x] = i;
    who[i] = x;
    ans += (idx[x - 1] == 0);
  }
  while(q--){
    int a , b;
    cin >> a >> b;
    a = who[a];
    b = who[b];
    if(a > b) swap(a , b);
    int ba = (idx[a - 1] < idx[a]);
    int bb = (idx[b - 1] < idx[b]);
    int aa = (idx[a + 1] > idx[a]);
    int ab = (idx[b + 1] > idx[b]);
    swap(idx[a] , idx[b]);
    swap(who[idx[a]] , who[idx[b]]);
    if(ba && !(idx[a - 1] < idx[a]))
      ans++;
    if(ab && !(idx[b + 1] > idx[b]))
      ans++;
    if(bb && !(idx[b - 1] < idx[b]))
      ans++;
    if(aa && !(idx[a + 1] > idx[a]) && b - a != 1)
      ans++;


    if(!ba && (idx[a - 1] < idx[a]))
      ans--;
    if(!ab && (idx[b + 1] > idx[b]))
      ans--;
    if(!bb && (idx[b - 1] < idx[b]))
      ans--;
    if(!aa && (idx[a + 1] > idx[a]) && b - a != 1)
      ans--;

    cout << ans << '\n';
  }


}

