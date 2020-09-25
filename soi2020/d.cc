#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<string> rotateSquare(vector<string> square) {
    vector<string> cp (square);
    for (int i = 0; i < square.size(); i++) {
        for (int j = 0; j < square.size(); j++) {
            square[i][j] = cp[j][square.size() - 1 - i];
        }
    }
    return square;
}


vector<string> flipSquare(vector<string> square) {
    vector<string> cp (square);
    for (int i = 0; i < square.size(); i++) {
        for (int j = 0; j < square.size(); j++) {
            square[i][j] = cp[j][i];
        }
    }
    return square;
}


int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    vector<string> q = flipSquare(s);
    int result = 0;
    for (int i = 0; i < 4; i++) {
        result += (s == q);
        s = rotateSquare(s);
    }
    cout << result << endl;
    return 0;
}

