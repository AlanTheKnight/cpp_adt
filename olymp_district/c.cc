#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int r;
    std::string n;
    int start_division;
    cin >> r >> n;
    if (r >= 0 && r <= 1600) {
        start_division = 3;
    } else if (r >= 1601 && r <= 1900) {
        start_division = 2;
    } else {
        start_division = 1;
    }
    bool participate = false;
    for (int i = 0; i < n.size(); i++) {
        int division = n[i] - '0';
        if (division == start_division) {
            cout << division << endl;
            participate = true;
        }
    }


    if (!participate) {
        for (int i = 0; i < n.size(); i++) {
            int division = n[i] - '0';
            if (division > start_division) {
                cout << division << "*";
            } else {
                cout << division;
            }
            cout << endl;
        }
    }

    return 0;
}

