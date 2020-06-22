#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool nums[n + 1];

    // Fill up the array
    for (int i = 0; i < n + 1; i++) {
        nums[i] = true;
    }

    // Erathosphenes
    int i = 2;
    while (i*i <= n) {
        if (nums[i]) {
            for (int x = i * i; x <= n; x += i) {
                nums[x] = false;
            }
        }
        i++;
    }

    // Print out
    for (int i = 2; i <= n; i++) {
        if (nums[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;

    return 0;
}