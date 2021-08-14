//Author: vietdoo
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair <int, int>
#define el '\n'
typedef long long LL;
const int N = 105;
const LL MAX = 1e8;
const int MIN = INT_MIN;

int n, m, k;

vector <pii> c[N];


void loadGraph() {
	cin >> n >> m >> k;
	int x, y, l;
	while (m--) {
		cin >> x >> y >> l;
		c[x].push_back({y, l});
		c[y].push_back({x, l});
	}

}

void dijkstra(int s, int f, int mode) {
	
	vector <LL> d(N, MAX);
	vector <int> trace(N, 0);
	vector <bool> vis(N, false);

	d[s] = 0;
	LL u, dd;
	while (true) {
		u = -2910;
		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				if (u == -2910 || d[u] > d[i]) {
					u = i;
				}
		}
		if (u == -2910 || u == f)
			break;

		vis[u] = true;
		for (auto v : c[u]) {
			dd = d[u] + v.se;
			if (d[v.fi] > dd) {
				d[v.fi] = dd;
				trace[v.fi] = u;
			}
		}
	}

	if (mode == 0) {
		cout << d[f];
	} else {
		stack <int> st;
		while (s != f) {
			st.push(f);
			f = trace[f];
		}
		st.push(s);
		cout << st.size();
		while (!st.empty()) {
			cout << ' ' << st.top();
			st.pop();
		}
	}
	cout << el;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE

	loadGraph();
	int mode, s, f;
	while (k--) {
		cin >> mode >> s >> f;
		dijkstra(s, f, mode);	
	}
	
	
	return 0;
}