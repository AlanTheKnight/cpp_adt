#include <algorithm>
#include <iostream>
using namespace std;


bool result(int *a) {
    sort(a, a+3);
    return (a[2] <= a[0] + a[1] + 1);
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a[3];
        for (int j = 0; j < 3; j++) {
            cin >> a[j];
        }
        cout << ((result(a)) ? "Yes" : "No") << endl;;
    }
    return 0;
}

