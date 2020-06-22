#include <iostream>

int main() {
    int N;
    std::cin >> N;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        std::cin >> temp;
        sum += temp;
    }
    std::cout << sum << '\n';
    return 0;
}
