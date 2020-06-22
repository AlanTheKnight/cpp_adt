#include <bits/stdc++.h>
using namespace std;

int convert(unsigned long long n, int base) {
    int carry = 1, answer = 0;
    while (n) {
        answer += (n % 10) * carry;
        carry *= base;
        n /= 10;
    }
    return answer;
}

int main() {
    int base;
    unsigned long long n;
    cin >> n >> base;
    cout << convert(n, base) << endl;
    return 0;
}
