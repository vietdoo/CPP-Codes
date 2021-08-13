//Author: vietdoo
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair<int, int>
typedef long long LL;
const int N = 105;
const int MAX = INT_MAX;
const int MIN = INT_MIN;

int n, m;
char a[N][N] = {0};
queue <pii> q;
map <pii, int> res;
map <pii, bool> vis;
pii s, f;


void bfs() {
	pii u;
	int x, y;
	res[s] = 0;
	res[f] = 0;
	int wx[]= {-1,0,1,0};
	int wy[]= {0,1,0,-1};
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			x = u.fi + wx[i];
			y = u.se + wy[i];
			pii v = {x, y};
			if (vis[v] == 0 && a[x][y] == '.') {
				vis[v] = true;
				res[v] = res[u] + 1;
				q.push(v);	
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'B') {
				s = make_pair(i, j);
			}
			if (a[i][j] == 'C') {
				f = make_pair(i, j);
				a[i][j] = '.';
			}
		}
	}

	q.push(make_pair(s.fi, s.se));
	bfs();
	cout << res[f];

	return 0;
}