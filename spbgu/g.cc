#include <iostream>
using namespace std;


int main() {
    int n;
    unsigned long long x;
    cin >> n >> x;

    long long A[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                A[i][j] = 0;
            } else {
                A[i][j] = x % 10000000;
                x = (1664525 * x + 1013904223) % 4294967296;
            }
        }
    }

    unsigned long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (j == k || k == i) continue;
                int m = min(min(A[i][j], A[j][k]), A[k][i]);
                // cout << m << endl;
                result += m;
            }
        }
    }
    cout << result << endl;
}
