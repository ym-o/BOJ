// Baekjoon Online Judge 9020
#include <iostream>
#include <cmath>  // for sqrt
using namespace std;

bool prime(int n) {  // prime discrimination
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;  // not prime number
		}
	}
	return true;  // prime number
}

void calculate(int n) {
	int array[2];
	array[0] = n / 2;
	array[1] = n - array[0];
	// first, divide n in half

	while (n > 4) {  // 4 is exception - O(log n)
		if (array[0] % 2 == 0) {  // if half is even
			array[0] -= 1;  // make odd
			array[1] = n - array[0];
		}
		else {  // if half is odd
			if (!prime(array[0]) || !prime(array[1])) {  // not prime number
				array[0] -= 2;  // make odd
				array[1] = n - array[0];
			}
			else {  // prime number
				break;  // out while
			}
		}
	}
	cout << array[0] << ' ' << array[1] << endl;  // standard output
}

int main(void) {
	int T;  // testcase number
	cin >> T;  // standard input

	int n;
	for (int i = 0; i < T; i++) {  // O(T)
		cin >> n;  // standard input
		calculate(n);  // call calculate function
	}

	return 0;  // always
}
// O(T*log n) = O(log n)