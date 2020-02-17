// Baekjoon Online Judge 10872
#include <iostream>
using namespace std;

int factorial(int n) {
	if (n <= 1)  // if n <= 1, return 1
		return 1;
	return n * factorial(n - 1);  // else, factorial calculation - recursion
}

int main(void) {
	int n;
	cin >> n;  // standard input
	cout << factorial(n) << endl;  // call factorial function

	return 0;  // always return 0
}