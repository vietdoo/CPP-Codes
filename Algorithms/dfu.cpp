//Author: vietdoo
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef long long LL;
const int N = 10009;
const int MAX = INT_MAX;
const int MIN = INT_MIN;

int n;
int cha[N];
int ranks[N] = {0};

int find(int u) {
	if (cha[u] == u) {
		return u;
	} else{
		cha[u] = find(cha[u]);
		return cha[u];
	}
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	if (a == b)
		return;
	if (ranks[a] == ranks[b])
		ranks[a]++;
	if (ranks[a] < ranks[b]) {
		cha[a] = b;
	} else {
		cha[b] = a;
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif // ONLINE_JUDGE
	for (int i = 1; i <= N; i++) {
		cha[i] = i;
	}

	cin >> n;
	int x, y, mode;
	while (n--) {
		cin >> x >> y >> mode;
		if (mode == 1) {
			join(x, y);
		} else {
			cout << (find(x) == find(y)) << '\n';
		}
	}
	

	return 0;
}