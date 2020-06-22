#include <bits/stdc++.h>
using namespace std;

int tasteMushroom(int a, int b, int c) {
	// Poisonous
	if (a == -1) {
		return -1;
	}

	// Misha thinks it's OK
	if (a == 1) {
		return 1;
	}

	// a == 0
	if (b == 1 || c == 1) {
		return 1;
	}
	return -1;
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << tasteMushroom(a, b, c) << endl;
	return 0;
}
