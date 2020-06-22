#include <bits/stdc++.h>
using namespace std;

const string TETRAD[16] = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111"
};

const string ALPHABET = "0123456789ABCDEF";

int findInAlphabet(char s) {
    for (int i = 0; i < 16; i++) {
        if (ALPHABET[i] == s) {
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
    if (s != "0000") {
        while (s.front() == '0') {
            s.erase(s.begin());
        }
    } else {
        s.erase(s.begin(), s.begin() + 3);
    }
}

string convert(string &s) {
    string binary;
    for (int i = 0; i < s.size(); i++) {
        binary += TETRAD[findInAlphabet(s[i])];
    }
    return binary;
}

int main() {
    string binary, hex;
    cin >> hex;
    binary = convert(hex);
    deleteLeadingZeroes(binary);
    cout << binary << endl;
    return 0;
}