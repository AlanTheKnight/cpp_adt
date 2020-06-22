#include <iostream>


int main() {
    int sum = 0;
    long long num;
    std::cin >> num;
    if (num < 0) {
        num *= -1;
    }
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    std::cout << sum << '\n';
    return 0;
}