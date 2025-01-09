#include <bits/stdc++.h>   
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif 
#define int long long
using namespace std;
#define f first
#define s second


main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<string ,int> mp;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string x;
    cin >> x;
    mp[x] = i;
  }
  string x , d;
  cin >> x >> d;
  cout << max(1LL , abs(mp[x] - mp[d]));
}
