#include <iostream>
#include <vector>
#include <string>


int main() {
    int n, m;
    std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::vector <int> remainders;
    std::cin >> n >> m;
    while (n >= m) {
        remainders.push_back(n % m);
        n /= m;
    }
    remainders.push_back(n);
    for (int i = remainders.size() - 1; i >= 0; i--) {
        std::cout << alphabet[remainders[i]];
    }
    std::cout << std::endl;
}
