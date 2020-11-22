#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int res = 0;
    int sum;
    cin >> sum;
    int a[5] = {100, 20, 10, 5, 1};
    for (int i = 0; i < 5; i++) {
        res += sum / a[i];
        sum %= a[i];
    }
    cout << res << endl;
    return 0;
}

