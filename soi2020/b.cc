#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    swap(s[0], s[s.size() - 1]);
    cout << s << endl;
    return 0;
}
