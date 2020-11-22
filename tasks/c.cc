#include <string>
#include <iostream>
using namespace std;


string process(string a, int k) {
    int x = 0;
    while (x < k) {
        for (int i = 0; i < a.length() - 1; i++) {
            if (a[i] == '1' && a[i+1] == '0') {
                char f = a[i];
                a[i] = a[i+1];
                a[i+1] = f;
                x++;
                break;
            }
            if (i == a.length() - 2) {
                return a;
            }
        }
    }
    
    return a;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k, y;
        cin >> k >> y;
        string a;
        cin >> a;
        cout << process(a, y) << '\n';
    }
    return 0;
}
