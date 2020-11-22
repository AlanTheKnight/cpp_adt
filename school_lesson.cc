#include <iostream>
using namespace std;


int main()
{
    int a, d, k;
    cin >> a >> d >> k;
    int sum = 0;

    for (int i = 0; i < k; i++) {
        sum += a + d*i;
    }

    cout << sum << endl;
}
