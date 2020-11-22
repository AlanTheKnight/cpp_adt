#include <string>
#include <iostream>
using namespace std;


string checkForWin(string a, string b) {
    if (a == b) return "Draw";
    if (a == "rock")
        return (b == "scissors") ? "Anna" : "Boris";
    if (a == "scissors")
        return (b == "paper") ? "Anna" : "Boris";
    return (b == "rock") ? "Anna" : "Boris";
}


int main(int argc, char const *argv[])
{
    string a, b;
    cin >> a >> b;
    cout << checkForWin(a, b) << endl;
    return 0;
}
