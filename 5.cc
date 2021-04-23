#include <iostream>
using namespace std;


int solve(string s) {
    if (s.length() != 5 || s[2] != '-' ||
        s[0] < 'A' || s[0] > 'H' ||
        s[1] < '1' || s[1] > '8' ||
        s[3] < 'A' || s[2] > 'H' || 
        s[4] < '1' || s[3] > '8')
        return 0;
    if (abs(s[0] - s[3]) * abs(s[1] - s[4]) == 2)
        return 1;
    return 2;
}


int main() {
 	string s;
    cin >> s;
    switch (solve(s))
    {
    case 0:
        cout << "ERROR";
        break;
    case 1:
        cout << "YES";
        break;
    case 2:
        cout << "NO";
        break;
    }
    cout << endl;

}