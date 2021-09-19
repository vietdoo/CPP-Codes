//Author: vietdoo
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pii pair <int, int>
#define el '\n'
typedef long long ll;
const int N = 100005;
const int MAX = INT_MAX;
const int MIN = INT_MIN;

int n, k, m;
int a[N];
ll s[N * 4], t[N * 4];

void lazyDown(int id) {
	int v = t[id];
	t[id << 1]+=v;
	t[(id << 1) + 1]+=v;
	s[id << 1]+=v;
	s[(id << 1) + 1]+=v;
	t[id] = 0;
}

int query(int id, int l, int r, int x, int y) {
	if (r < x || l > y) {
		return 0;
	}
	if (l >= x && r <= y) {
		return s[id];
	}
	lazyDown(id);
	int mid = (l + r) / 2;
	return query(id << 1, l, mid, x, y) + query((id << 1) + 1, mid + 1, r, x, y);
}

void update(int id, int l, int r, int x, int y) {
	if (r < x || l > y) {
		return;
	}
	if (x <= l && y >= r){
		s[id] ++;
		t[id] ++;
		return;
	}
	lazyDown(id);
	int mid = (l + r) / 2;
	update(id << 1, l, mid, x, y);
	update((id << 1) + 1, mid + 1, r, x, y);
	s[id] = s[id << 1] + s[(id << 1) + 1];
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	cin >> n;
	cin >> k;
	int x, y;
	while (k--) {
		cin >> m >> x >> y;
		if (m == 0) {
			update(1, 1, n, x, y);
		} else {
			cout << query(1, 1, n, x, y) << el;
		}
	}
	cout << el << s[1];

	return 0;
}