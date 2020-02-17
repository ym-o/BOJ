// Baekjoon Online Judge 10250
#include <iostream>
using namespace std;

int roomNumber() {
	int H, W, N;  // height(floor), width(room), guest number
	cin >> H >> W >> N;  // standard input

	int **hotel = new int*[H];  //dynamic allocation
	for (int i = 0; i < H; i++) {
		hotel[i] = new int[W];  // dynamic allocation
	}

	int room, count = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			count++;
			if (count == N) {
				room = ((j + 1) * 100) + (i + 1);
			}
		}
	}

	for (int i = 0; i < H; i++) {
		delete[] hotel[i];  // delete
	}
	delete[] hotel;  // delete

	return room;
}

int main(void) {
	int T;  // testcase number
	cin >> T;  // standard input

	for (int i = 0; i < T; i++) {  // repeat
		cout << roomNumber() << endl;  // call roomNumber function
	}

	return 0;  // always return 0
}