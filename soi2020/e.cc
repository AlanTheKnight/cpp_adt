#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string buf;
    getline (cin, buf);
    if (buf == "print")
    {
        getline (cin, buf);
        for (int i = 0; i < buf.size(); i++)
            cout << (int) (buf[i]) << " ";
    }
    else
    {
        int code;
        while (cin >> code)
            cout << (char) (code);
    }
    cout << endl;
    return 0;
}
