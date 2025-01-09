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
	std::vector<string> v(n);
	std::vector<std::vector<bool>> vis(n , std::vector<bool>(m));
	std::vector<std::vector<int>> from(n , std::vector<int>(m));
	for(string& i : v)
		cin >> i;
	ii start , end;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == 'A') start = {i , j};
			if(v[i][j] == 'B') end = {i , j};
		}
	}
	from[start.f][start.s] = -1;
	auto bfs = [&](int r, int c){
		int ans = 0;
		auto valid = [&](int i, int j){
			return i >= 0 && j >= 0 && i < n && j < m && vis[i][j] == 0 && v[i][j] != '#';
		};
		queue<array<int , 3>> q;  // i , j , from (0 => up , 1 => right,  2 => down , 3 => left)
		q.push({r , c , -1});
		while(q.size()){
				for(int i=0; i<(int)q.size(); i++){
				array<int , 3> cur = q.front();
				q.pop();
				//cout << cur[0] << ' ' << cur[1] << '\n';
				if(make_pair(cur[0] , cur[1]) == end){
					return ans;
				}
				for(int k=0; k<4; k++){
					int ni = cur[0] + dx[k];
					int nj = cur[1] + dy[k];
					if(valid(ni , nj)){
						from[ni][nj] = k;
						q.push({ni , nj , k});
						vis[ni][nj] = true;
					}
				}
			}
			ans ++;
		}
		return -1LL;
	};
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(v[i][j] == 'A'){
				start = {i , j};
				int ans = bfs(i , j);
				if(ans == -1){
					cout << "NO";
					return;
				}
				cout << "YES\n";
				ii e = end;
				std::vector<char> d;
				while(e != start){
					if(from[e.f][e.s] == 0) {
						d.push_back('D');
						e = {e.f - 1 , e.s};
					}
					else if(from[e.f][e.s] == 1) {
						d.push_back('L');
						e = {e.f , e.s + 1};
					} 
					else if(from[e.f][e.s] == 2) {
						d.push_back('U');
						e = {e.f + 1 , e.s};
					}
					else if(from[e.f][e.s] == 3) {
						d.push_back('R');
						e = {e.f , e.s - 1};
					}
				}
				cout << d.size() << '\n';
				reverse(d.begin() , d.end());
				for(char c : d){
					cout << c;
				}
				return ;
			}
		}
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