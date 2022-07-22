#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 200000 + 10;
bool vis[MAXN];

class Node{
  public:
  	int val, cur;
  	Node(int val = 0, int cur = 0) : val(val), cur(cur) {}
};
queue<Node> q;

void getD(int& n, int& k) {
  memset(vis, 0, sizeof(vis));
  cin >> n >> k;
}

void bfs(int& n, int& k) {
  q.push(Node(n, 0));
  vis[n] = true;
  while(!q.empty()) {
  	Node temp = q.front();
  	if(temp.val == k) {
  	  cout << temp.cur << endl;
	  return;	
	}
  	q.pop();
  	int nval = temp.val + 1;
  	if(nval <= MAXN && !vis[nval]) {
  	  vis[nval]	= true;
  	  q.push(Node(nval, temp.cur+1));
	}
	nval = temp.val - 1;
	if(nval >= 0 && !vis[nval]) {
	  vis[nval] = true;
	  q.push(Node(nval, temp.cur+1));
	}
	nval = temp.val * 2;
	if(nval <= MAXN && !vis[nval]) {
	  vis[nval] = true;
	  q.push(Node(nval, temp.cur+1));
	} 
  }
}

int main() {
  int n, k;
  getD(n, k);
  bfs(n, k);
  return 0;
} 
