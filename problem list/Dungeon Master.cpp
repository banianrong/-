#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 30;
int map[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

class Point{
  public:
  	int l, r, c, cur;
  	Point(int l = 0, int r = 0, int c = 0, int cur = 0) : l(l), r(r), c(c), cur(cur) {}
};

bool getD(int& l, int& r, int& c, int& sl, int& sr, int& sc) {
  cin >> l >> r >> c;
  if(l == r && r == c && r == 0) return false;
  memset(vis, 0, sizeof(vis));
  for(int i = 0; i < l; i++) {
    for(int j = 0; j < r; j++) {
      for(int k = 0; k < c; k++) {
      	char ch;
      	cin >> ch;
      	switch(ch) {
      	  case '.' : map[i][j][k] = 1; break;
		  case '#' : map[i][j][k] = 0; break;
		  case 'S' : map[i][j][k] = 2; sl = i; sr = j; sc = k; break;
		  case 'E' : map[i][j][k] =	3; break;
		}
	  }
	}
  }
  return true;
}

bool bfs(int& l, int& r, int& c, int& sl, int& sr, int& sc) {
  queue<Point> q;
  q.push(Point(sl, sr, sc));
  vis[sl][sr][sc] = true;
  while(!q.empty()) {
  	Point ptr = q.front();
  	q.pop();
  	if(map[ptr.l][ptr.r][ptr.c] == 3) {
  	  cout << "Escaped in " << ptr.cur << " minute(s)." << endl;
  	  return true;	
	}
	for(int i = 0; i < 6; i++) {
	  int nl = ptr.l + dz[i], nr = ptr.r + dx[i], nc = ptr.c + dy[i];
	  if(nl >= 0 && nl < l && nr >= 0 && nr < r && nc >= 0 && nc < c && map[nl][nr][nc] && !vis[nl][nr][nc]) {
	  	vis[nl][nr][nc] = true;
	  	q.push(Point(nl, nr, nc, ptr.cur+1));
	  } 
	}
  }
  return false;
}

int main() {
  int l, r, c, sl, sr, sc;
  while(getD(l, r, c, sl, sr, sc)) {
    if(!bfs(l, r, c, sl, sr, sc)) cout << "Trapped!" << endl;
  }	
  return 0;
} 
