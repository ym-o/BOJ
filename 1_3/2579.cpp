// BOJ 2579
#include <iostream>
#include <vector>
#include <algorithm>  // for max
using namespace std;

int maxScore(vector<int> v) {  // max score function
	int result = 0;  // max score
	vector<int> score;
	score.push_back(v[0]);  // score[0] = 0
	score.push_back(score[0] + v[1]);  // score[1] = 0 + stair[1]
	score.push_back(score[1] + v[2]);  // score[2] = 0 + stair[1] + stair[2]

	for (int i = 3; i < v.size(); i++) {  // score[i] -> i is more than 2
		int a = score[i - 2] + v[i];
		int b = score[i - 3] + v[i - 1] + v[i];
		score.push_back(max(a, b));  // push the greater of a and b
	}
	result = score.back();  // last number(score) of score

	return result;  // return max score
}

int main(void) {
	int num, temp;  // number of stair, score of stair
	cin >> num;  // standard input

	vector<int> stair;
	stair.push_back(0);  // push 0 as 1st element

	for (int i = 0; i < num; i++) {
		cin >> temp;  // standard input
		stair.push_back(temp);  // push score of stair in stair vector
	}

	cout << maxScore(stair) << endl;  // print max score

	return 0;  // always return 0
}