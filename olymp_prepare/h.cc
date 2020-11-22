#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


int main(int argc, char const *argv[])
{
    int n; cin >> n;
    char right[n];
    for (int i = 0; i < n; i++) {
        cin >> right[i];
    }
    int m; cin >> m;
    vector<vector<char>> data(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> data[i][j];
        }
    }

    set<pair<int, int>> ans;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j == i) continue;
            set<int> f1, f2, s1, s2;
            for (int x = 0; x < n; x++) {
                if (data[i][x] == right[x])
                    f1.insert(x);
                else
                    f2.insert(x);
                if (data[j][x] == right[x])
                    s1.insert(x);
                else
                    s2.insert(x);
            }
            int half = f1.size() / 2;
            int half1 = f2.size() / 2;
            set<int> right;
            set_intersection(f1.begin(), f1.end(), s1.begin(), s1.end(), inserter(right, right.begin()));
            set<int> mistakes;
            set_intersection(f2.begin(), f2.end(), s2.begin(), s2.end(), inserter(mistakes, mistakes.begin()));
            if (right.size() > half && mistakes.size() > half1) {
                ans.insert(make_pair(min(i, j), max(i, j)));
            }
        }
    }

    cout << ans.size() << endl;
    for (auto i : ans) {
        cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    cout << endl;
    return 0;
}

