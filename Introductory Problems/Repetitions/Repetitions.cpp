#include <bits/stdc++.h>   
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define int long long


main() {
  string s;
  cin >> s;
  int ans = 1 , cnt = 1;
  for(int i=1; i<s.size(); i++){
    if(s[i] == s[i - 1]){
      cnt ++;
      ans = max(ans , cnt);
    } else {
      cnt = 1;
    }
  }
  cout << ans;
}


