#include <iostream>
#include <cmath>

// Solution for https://codeforces.com/group/LTFKtHGeF5/contest/208099/problem/A

int main() {
    double a, b, c;
    double d;
    std::cin >> a >> b >> c;
    d = b*b - 4*a*c;
    if (d < 0) {
        printf("no solutions\n");
    } else if (d == 0) {
        printf("one solution\n");
        printf("%.4f\n", (double)(-b / (2*a)));
    } else {
        printf("two solutions\n");
        printf("%.4f\n", (double)((-b + std::sqrt(d)) / (2*a)));
        printf("%.4f\n", (double)((-b - std::sqrt(d)) / (2*a)));
    }
    return 0;
}
