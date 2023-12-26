#include <bits/stdc++.h>    
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include <deb.h>
#else
#define deb(x)
#endif
using namespace std;
#define ll long long
#define oo 1e17 
#define int ll
#define mod 1000000007
#define f first
#define s second
#define popcnt __builtin_popcountll
#define clr(v, d) memset(v,d,sizeof(v))
#define ii pair<int,int>
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
 
// using namespace __gnu_pbds;
// typedef tree<ii,null_type,less<ii>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;
 
int dx[] = {0 , 1 , 0 , -1};
int dy[] = {1 , 0 , -1 , 0};
 
int n , m;
 
void solve(int E){
	cin >> n >> m;
	std::vector<string> v(n);
	for(string &i : v)
		cin >> i;
	queue<array<int,3>>mq , pq;
	std::vector<std::vector<int>> m_dist(n , std::vector<int>(m , oo));
	std::vector<std::vector<char>> from(n , std::vector<char>(m , '%'));
	for(int i=0 ;i<n ;i++){
		for(int j=0 ;j<m ;j++){
			if(v[i][j] == 'M') mq.push({i , j , 0}) , m_dist[i][j] = 0;
			if(v[i][j] == 'A') pq.push({i , j , 0});
		}
	}
	auto valid = [&](int r , int c){
		return r >= 0 && c >= 0 && c < m && r < n && v[r][c] != '#';
	};
	ii st = {pq.front()[0] , pq.front()[1]} ; 
	while(mq.size()){
		array<int,3> cur = mq.front();
		mq.pop();
 
		for(int k=0 ;k<4 ; k++){
			int ni = cur[0] + dx[k];
			int nj = cur[1] + dy[k];
			if(!valid(ni , nj)) continue;
			if(m_dist[ni][nj] > m_dist[cur[0]][cur[1]] + 1){
				m_dist[ni][nj] = m_dist[cur[0]][cur[1]] + 1;
				mq.push({ni , nj, m_dist[ni][nj]});
			}
		}	
	}
	while(pq.size()){
		array<int,3> cur = pq.front();
		pq.pop();
		if(cur[0] == n - 1 || cur[0] == 0 || cur[1] == m - 1  || cur[1] == 0){
			cout << "YES\n";
			std::vector<char> ans;
			ii now = {cur[0]  , cur[1]};
			while(now.f != st.f || now.s != st.s){
				ans.push_back(from[now.f][now.s]);
				if(from[now.f][now.s] == 'D'){
					now.f--;
				} else if(from[now.f][now.s] == 'U'){
					now.f++;
				} else if(from[now.f][now.s] == 'L'){
					now.s++;
				} else {
					now.s--;
				}
			}
			reverse(ans.begin() , ans.end());
			cout << ans.size() << '\n';
			for(char x : ans) cout << x;
			return;
		}
 
		for(int k=0 ;k<4 ; k++){
			int ni = cur[0] + dx[k];
			int nj = cur[1] + dy[k];
			if(valid(ni , nj) && m_dist[ni][nj] > cur[2] + 1 && from[ni][nj] == '%'){
				if(k == 0){
					from[ni][nj] = 'R';
				} else if(k == 1){
					from[ni][nj] = 'D';
				} else if(k == 2){
					from[ni][nj] = 'L';
				} else if(k == 3){
					from[ni][nj] = 'U';
				}
				pq.push({ni , nj , cur[2] + 1});
			}
		}	
	}
	cout << "NO";
}
 
 
 
int32_t main() {
	 cin.tie(0);cin.sync_with_stdio(0);
	 cout.tie(0);cout.sync_with_stdio(0);
	 //freopen("sticks.in", "r", stdin);
	 //freopen("output.txt", "w", stdout);  
	 int t = 1;
	 //cin >> t;
	  for (int L = 0; L < t; L++){
	    solve(L);  
	  }
}