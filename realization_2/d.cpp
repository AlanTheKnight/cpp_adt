#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


void scan(std::vector<long int> *a) {
    a->clear();
    int n;
    long num;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        a->push_back(num);
    }
}

void sort(std::vector<long int> *a) {
    std::sort(a->begin(), a->end());
}

void print(std::vector<long int> *a) {
    for (auto i : (*a)) {
        std::cout << i << ' '; 
    }
    std::cout << std::endl;
}

void sum(std::vector<long int> *a) {
    int sum = 0;
    for (auto i : (*a)) {
        sum += i;
    }
    std::cout << sum << std::endl;
}

int main() {
    int n;
    std::string option;
    std::vector<long int> a;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> option;
        if (option == "print") {
            print(&a);
        } else if (option == "scan") {
            scan(&a);
        } else if (option == "sum") {
            sum(&a);
        } else {
            sort(&a);
        }
    }
    return 0;
}