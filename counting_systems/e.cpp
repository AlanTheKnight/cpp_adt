#include <bits/stdc++.h>
using namespace std;

const string TETRAD[16] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
};

const string ALPHABET = "0123456789ABCDEF";

int findInTetrad(string s) {
    for (int i = 0; i < 16; i++) {
        if (TETRAD[i] == s) {
            return i;
        }
    }
    return -1;
}

void fillWithZeroes(string &s) {
    while (s.size() % 4 != 0) {
        s.insert(0, "0");
    }
}

void deleteLeadingZeroes(string &s) {
    while (s.front() == '0') {
        s.erase(s.begin());
    }
}

string convert(string &binary) {
    string hex;
    for (int i = 0; i < binary.size(); i += 4) {
        hex += ALPHABET[findInTetrad(binary.substr(i, 4))];
    }
    return hex;
}

int main() {
    string binary, hex;
    cin >> binary;
    fillWithZeroes(binary);
    hex = convert(binary);
    cout << hex << endl;
    return 0;
}