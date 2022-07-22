#include<iostream>
#include<cstring>
using namespace std;

const int MAXN = 8;
bool map[MAXN][MAXN];
bool vis[MAXN];
int ans;

bool getD(int& n, int& m) {
  cin >> n >> m;
  if((~n) | (~m)) {
  	for(int i = 0; i < n; i++) {
  	  for(int j = 0; j < n; j++) {
  	    char ch;
		cin >> ch;
		map[i][j] = (ch == '#') ? false : true;	
	  }	
	}
	ans = 0;
	memset(vis, 0, sizeof(vis));
  }else{ 
    return false;
  }
  return true;
}

void dfs(int begin, int cur, int& n, int& m) { 
  if(cur == m) {
    ans++;
    return;
  }
  if(begin == n) return;
  for(int row = begin; row < n; row++) {
  	for(int i = 0; i < n; i++) {
  	if(vis[i] || map[row][i]) continue;
  	vis[i] = true; 
  	dfs(row+1, cur+1, n, m);
  	vis[i] = false;
    }
  }
}

int main() {
  int n, m;
  while(getD(n, m)) {
  	dfs(0, 0, n, m);
  	cout << ans << endl;
  }
  return 0;
}
