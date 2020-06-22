#include <bits/stdc++.h>
using namespace std;

const string TRIAD[8] = {
    "000", "001", "010", "011",
    "100", "101", "110", "111"
};

int findInTriad(string s) {
    for (int i = 0; i < 8; i++) {
        if (TRIAD[i] == s) {
            return i;
        }
    }
    return -1;
}

string convert(string &s) {
    string octal;
    for (int i = 0; i < s.size(); i += 3) {
        octal.append(to_string(findInTriad(s.substr(i, 3))));
    }
    return octal;
}

int main() {
    string binary, octal;
    cin >> binary;
    octal = convert(binary);
    cout << octal << endl;
    return 0;
}