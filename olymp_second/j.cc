#include <iostream>
using namespace std;


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * b == c * d)
		cout << "E";
	else if (a * b > c * d)
		cout << "M";
	else
		cout << "P";
	cout << endl;
	return 0;
}
