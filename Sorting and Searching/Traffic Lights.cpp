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

  int x , n;
  cin >> x >> n;
  set<int> s;
  multiset<int> diff;
  s.insert(x);
  s.insert(0);
  diff.insert(x);
  while(n--){
    int l;
    cin >> l;
    auto a = s.upper_bound(l);
    auto b = a;
    b--;
    auto c = diff.lower_bound(*a - *b);
    diff.insert(*a - l);
    diff.insert(l - *b);
    diff.erase(c);
    deb(diff)
    s.insert(l);
    cout << *diff.rbegin() << ' ';
  }
}
