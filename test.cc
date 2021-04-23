#include <iostream>
using namespace std;


int main() {
    int n;
    int ans = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) ans = true;
    }
    cout << ((ans) ? "Yes" : "No") << endl;
}
