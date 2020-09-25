#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int x, y, z;
    cin >> x >> y >> z;

    int diff = z * 3;
    int new_x, new_y;

    for (int i = 1; i < z; i++) {
        for (int j = i; j < z; j++) {
            int a = i, b = j - i, c = z -j;
            if (max(a, max(b, c)) - min(a, min(b, c)) <= 1) {
                int new_diff = abs(x - i) + abs(y - j);
                if (new_diff < diff) {
                    diff = new_diff;
                    new_x = i; new_y = j;
                }
            }
        }
    }

    cout << diff << endl << new_x << " " << new_y << endl;
    return 0;
}

