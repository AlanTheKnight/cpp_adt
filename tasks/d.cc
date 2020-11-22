#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (max(a, max(b, c))) << endl;
    }
    return 0;
}

