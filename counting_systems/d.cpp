#include <bits/stdc++.h>
using namespace std;

const string TRIAD[8] = {
    "000", "001", "010", "011",
    "100", "101", "110", "111"
};

void deleteLeadingZeroes(string &s) {
    while (s.front() == '0') {
        s.erase(s.begin());
    }
}

string convert(string &s) {
    string binary;
    for (int i = 0; i < s.size(); i++) {
        binary.append(TRIAD[(int)s[i] - 48]);
    }
    return binary;
}

int main() {
    string binary, octal;
    cin >> octal;
    binary = convert(octal);
    deleteLeadingZeroes(binary);
    cout << binary << endl;
    return 0;
}