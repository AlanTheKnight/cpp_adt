#include <iostream>


int main() {
    long long x, y, z;
    std::cin >> x >> y >> z;
    if (x > 0 & y > 0 & z > 0 & ((x*x + y*y == z*z) || (z*z + y*y == x*x) || (z*z + x*x == y*y))) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    std::cout << std::endl;
    return 0;
}