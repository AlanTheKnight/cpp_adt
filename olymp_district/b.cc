#include <bits/stdc++.h>
using namespace std;


long long int getNum(long long a) {
    return ((a * (a - 1)) / 2) + 1;
}


int main(int argc, char const *argv[])
{
    long long a, b, k;
    cin >> a >> b >> k;
    int row_width = a;
    while (row_width <= b) {
        long long num = getNum(row_width);
        for (int i = 1; i <= row_width && i <= k; i++) {
            cout << num << ' ';
            num++;
        }
        cout << '\n';
        row_width++;
    }
}


