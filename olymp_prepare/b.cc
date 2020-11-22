#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> data;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> t = {a, b, c};
        data.push_back(t);
    }

    for (int i = 1; i < m + 1; i++) {
        int min = 0, max = 0;
        for (auto j : data) {
            if (j[0] < 0) {
                if (j[1] == i)
                    min -= j[0];
            } else if (j[0] > 0){
                if (j[2] == i)
                    max += j[0];
            }
        }
        s -= min;
        if (s < 0) {
            cout << "YES" << '\n';
            return 0;
        }
        s += max;
    }
    cout << "NO" << '\n';
    return 0;
}

