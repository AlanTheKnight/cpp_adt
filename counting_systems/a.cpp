#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::vector <int> remainders;
    std::cin >> n >> m;
    while (n >= m) {
        remainders.push_back(n % m);
        n /= m;
    }
    remainders.push_back(n);
    for (int i = remainders.size() - 1; i >= 0; i--) {
        std::cout << remainders[i];
    }
    std::cout << std::endl;
}
