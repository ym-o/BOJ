// Baekjoon Online Judge 1712
#include <iostream>
using namespace std;

int main(void) {
	int A, B, C, n;
	// A-fixed cost, B-variable cost, C-laptop price, n-number of laptop
	
	cin >> A >> B >> C;  // standard input
	
	// C*n > A + B*n --> n(C-B) > A --> C-B > 0
	if (C <= B) {  // if breakeven point does not exist
		n = -1;  // n is -1
	}
	else {  // if breakeven point exists
		n = A / (C - B) + 1;  // n is bigger than A / (C - B)
	}
	cout << n << endl;  // standard output

	return 0;  // always return 0
}