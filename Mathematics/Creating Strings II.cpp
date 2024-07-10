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

const int mod = 1e9 + 7;
const int N = 1e6 + 1;

int fact[N] , inv[N];

int mul(int a , int b){
  return ((a % mod) * (b % mod)) % mod;
}

int exp(int a, int b, int m) {
    int res = 1;
    while (b) {
        if (b & 1)res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}


main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  fact[0] = inv[0] = 1;
  for(int i=1; i<N; i++){
    fact[i] = mul(i , fact[i - 1]);
    inv[i] = exp(fact[i] , mod - 2 , mod);
  }

  string s;
  cin >> s;

  int ans = fact[s.size()];
  std::vector<int> fr(26);
  for(char c : s){
    fr[c - 'a']++;
  }
  for(int i=0; i<26; i++){
    ans = mul(ans , inv[fr[i]]);
  }
  cout << ans ;
}
