// BOJ 2631
#include <iostream>
#include <vector>
#include <algorithm>  // for lower_bound
using namespace std;

int main(void) {
	int n, a;
	cin >> n;  // standard input

	vector<int> child;
	vector<int> LIS;
	vector<int> parent(n + 1, -1);  // initialize -1

	for (int i = 0; i < n; i++) {
		cin >> a;  // standard input
		child.push_back(a);  // push in child vector
	}

	LIS.push_back(child[0]);  // push 1st child in LIS vector
	
	// LIS(Longest Increasing Sequence) »ç¿ë
	for (int i = 1; i < n; ++i) {
		if (LIS.back() < child[i]) {
			parent[child[i]] = LIS.back();
			LIS.push_back(child[i]);
		}
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), child[i]);
			*it = child[i];
			if (it != LIS.begin()) {
				parent[child[i]]=*(--it);
			}
		}
	}

	int count = 0, number = LIS.back();
	while (number != -1) {  // out condition : number == -1
		count++;  // immovable children increase
		// cout << number << endl;  // immovable children
		number = parent[number];
	}
	cout << n - count << endl;  // all children - immovable children

	return 0;  // always return 0
}