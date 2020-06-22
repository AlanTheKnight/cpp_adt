#include <iostream>
 
int main() {
    int a, b;
    std::cin >> a >> b;
    (a > b) ? std::cout << a : std::cout << b;
    std::cout << std::endl;
}

