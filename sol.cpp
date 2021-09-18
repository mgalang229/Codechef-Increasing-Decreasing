#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// mark all the distinct elements
		sort(a.begin(), a.end());
		vector<bool> visited(n, false);
		for (int i = 0; i + 1 < n; i++) {
			if (a[i] != a[i + 1]) {
				visited[i] = true;
			}
		}
		// edge case for sequences with 2 or more elements:
		// check if the last element is not equal to its previous element
		if (n >= 2) {
			if (a[n - 1] != a[n - 2]) {
				visited[n - 1] = true;
			}
		}
		// store all the distinct elements in 'first_half' and the remaining
		// elements in 'second_half'
		vector<int> first_half, second_half;
		for (int i = 0; i < n; i++) {
			if (visited[i]) {
				first_half.push_back(a[i]);
			} else {
				second_half.push_back(a[i]);
			}
		}
		// check if there are elements in 'first_half' and 'second_half':
		// if yes, then check if the last element from the 'first_half'
		// is equal to the first element in the 'second_half' because
		// this would violate the strictly decreasing property
		if ((int) first_half.size() > 0 && (int) second_half.size() > 0) {
			if (first_half.back() == second_half.back()) {
				cout << "NO" << '\n';
				continue;
			}
		}
		// otherwise, reverse 'second_half' to make it in decreasing order
		// also, don't forget to check if 'second_half' is in strictly
		// decreasing order (no identical elements)
		reverse(second_half.begin(), second_half.end());
		bool checker = true;
		for (int i = 0; i + 1 < (int) second_half.size(); i++) {
			if (second_half[i] <= second_half[i + 1]) {
				checker = false;
				break;
			}
		}
		if (!checker) {
			cout << "NO" << '\n';
			continue;
		}
		// if 'second_half' is a valid strictly decreasing order, then
		// print the output based on the format from the problem statement 
		cout << "YES" << '\n';
		for (int i = 0; i < (int) first_half.size(); i++) {
			cout << first_half[i] << " ";
		}
		for (int i = 0; i < (int) second_half.size(); i++) {
			cout << second_half[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}
