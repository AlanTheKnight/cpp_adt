#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, count[201] = {};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        count[d + 100] += 1;
    }
    for (int i = 0; i < 201; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i - 100 << '\n';
        }
    }
    return 0;
}
