//Author: vietdoo
#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pii pair <int, int>
#define pb push_back
//#define int long long
#define el '\n'
#define len(a) a.length()
 
const double pi = acos(-1.0);
const int mod = 1000000007;
const int oo = 2e9 + 9;
const int N = 1e6 + 9;
 
int t = 1, n, m, k;
int lps [N]{0}; 
 
void kmp(string s1, string s2) {
	int m = len(s1), n = len(s2);
 
	for (int i = 1; i < n; i++) {
		if (s2[i] == s2[lps[i - 1]]) {
			lps[i] = lps[i - 1] + 1;
		} 
	} 
 
	int i = 0, j = 0;
	while (i < m) {
		if (s1[i] == s2[j]) {
			i++;
			j++;
		} else {
			j = lps[j - 1];
			if (j == 0 && s2[0] != s1[i]) {
				i++;
				}
		}
		if (j == n) {
			cout << i - j + 1 << ' ';
			j = lps[j - 1];
		}
	}
}
 
void Main () {
	string s1 = "abcabdababcab";
	string s2 = "abcab";
	cin >> s1 >> s2;
	kmp(s1, s2);
}
 
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif 
	
	//cin >> t;
	while (t--) {
		Main();
	}
 
	return 0;
}
