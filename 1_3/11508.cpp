// BOJ 11058
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>  // for greater
using namespace std;

int main(void) {
	int n, price, sum = 0;
	cin >> n;  // standard input

	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> price;  // standard input
		v.push_back(price);  // push in vector for sort
		sum += price;  // total sum
	}
	sort(v.begin(), v.end(), greater<int>());  // descending order sort
	
	for (int i = 2; i < v.size(); i += 3) {
		sum -= v[i];  // total sum - (2, 5, 8, 11, ...)
	}
	cout << sum << endl;  // print

	return 0;  // always return 0
}