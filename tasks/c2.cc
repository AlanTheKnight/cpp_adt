#include <iostream>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[])
{
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        int a[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        sort(a, a+n, std::greater<>());
        for (int j = 0; j < n; j++) {
            cout << a[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}

