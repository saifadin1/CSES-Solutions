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

int dx[8]={0,1,0,-1,1,1,-1,-1};
int dy[8]={1,0,-1,0,1,-1,-1,1};

const int N = 2e5 + 123;

void sovle(){
	int n , m;
	cin >> n >> m;
	std::vector<string> v(n);
	std::vector<std::vector<bool>> vis(n , std::vector<bool> (m , false));
	for(string& i : v)
		cin >> i;

	auto bfs = [&](int i, int j){
		queue<ii> q;
		q.push({i , j});
		vis[i][j] = true;
		while(q.size()){
			auto valid = [&](int i, int j){
				return i >= 0 && j >= 0 && i < n && j < m && vis[i][j] == false && v[i][j] == '.';  
			};
			ii cur = q.front();
			q.pop();
			for(int k=0; k<4; k++){
				int ni = cur.f + dx[k];
				int nj = cur.s + dy[k];
				if(valid(ni , nj)){
					q.push({ni , nj});
					vis[ni][nj] = true;
				}
			}
		}
	};

	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(!vis[i][j] && v[i][j] == '.'){
 				ans ++;
				bfs(i , j);
			}
		}
	}
	cout << ans;
}


main() {
    cin.tie(0);cin.sync_with_stdio(0);
    cout.tie(0);cout.sync_with_stdio(0);
   //  freopen("ladder.in", "r", stdin);
	 	// freopen("ladder.out", "w", stdout);  
    int t = 1;
  	//cin >> t;

     for (int L = 0; L < t; L++){
     	//cout << "Case " << L + 1 << ": ";
       sovle();    
     }
}