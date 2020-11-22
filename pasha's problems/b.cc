#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool checkIfBase5Valid(int n) {
    if (n == 0) return false;
    while (n % 5 == 0) {
        n /= 5;
    }
    return (n == 1);
}


bool checkIfNumIsFactorial(int num) {
    if (num == 0) return false;
    for (int i = 1; ; i++) {
        if (num % i == 0) {
            num /= i;
        } else {
            break;
        }
    }
    if (num == 1)
        return true;
    return false;
}


int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<int> nums;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        if (k % 2 == 0) a++;
        if (checkIfBase5Valid(abs(k))) b++;
        if (checkIfNumIsFactorial(k)) c++; 
    }
    cout << a << ' ' << b << ' ' << c << endl;
    return 0;
}

