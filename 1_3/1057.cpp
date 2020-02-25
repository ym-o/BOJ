// BOJ 1057
#include <iostream>
using namespace std;

int main(void) {
	int n, jm, hs, round = 0;
	cin >> n >> jm >> hs;  // standard input

	while (jm != hs) {  // out condition : jm == hs
		jm = jm - (jm / 2);  // jm's next number
		hs = hs - (hs / 2);  // hs's next number
		round++;  // round increase
	}
	cout << round << endl;  // result print

	return 0;  // always return 0
}