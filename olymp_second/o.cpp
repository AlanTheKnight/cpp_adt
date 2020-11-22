#include <iostream>
using namespace std;


int main() {
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	int elev_time = (k-1)*b + (n-1)*b;
	int step_time = (n-1)*a;
	cout << elev_time << ' ' << step_time << endl;
	return 0;
}
