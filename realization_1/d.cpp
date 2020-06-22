#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a > b) {
        b = a;
    }
    (c > b) ? std::cout << c : std::cout << b;
    std::cout << std::endl;
}