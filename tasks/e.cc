#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int t, n, m;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << ((n % m == 0) ? "YES" : "NO") << endl;
    }
    return 0;
}

