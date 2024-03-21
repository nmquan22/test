#include <bits/stdc++.h>
#define long long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stack<int> s;
	vector<int> l(n), r(n);

	s = stack<int>();
	for (int i = 0; i < n; i++) {
		while (s.size() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if (s.size()) {
			l[i] = s.top() + 1;
		} else {
			l[i] = 0;
		}
		s.push(i);
	}
	s = stack<int>();
	for (int i = n - 1; i >= 0; i--) {
		while (s.size() && a[s.top()] >= a[i]) {
			s.pop();
		}
		if (s.size()) {
			r[i] = s.top() - 1;
		} else {
			r[i] = n - 1;
		}
		s.push(i);
	}

	vector<int> m(n + 1);
	for (int i = 0; i < n; i++) {
		int j = r[i] - l[i] + 1;
		m[j] = max(m[j], a[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		m[i] = max(m[i], m[i + 1]);
	}
	for (int i = 1; i <= n; i++) {
		cout << m[i] << " ";
	}

	return 0;
}