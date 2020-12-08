#include <bits/stdc++.h>
using namespace std;


map<int, int> countingSort(vector<int> &a) {
    map<int, int> result;
    for (auto i : a) {
        if (result.count(i) != 0)
            result[i] += 1;
        else
            result[i] = 1;
    }
    return result;
}


map<int, int> uniteTwoMaps(map<int, int> &a, map<int, int> &b) {
    map<int, int> result;
    for (const auto &myPair : a) {
        if (b.count(myPair.first) != 0) {
            result[myPair.first] = max(myPair.second, b[myPair.first]);
        } else {
            result[myPair.first] = myPair.second;
        }
    }
    for (const auto &myPair : b) {
        if (a.count(myPair.first) == 0) {
            result[myPair.first] = myPair.second;
        }
    }
    return result;
}


int main(int argc, char const *argv[])
{
    int k;
    cin >> k;
    int m, n;
    cin >> m;
    vector<int> first (m);
    for (int i = 0; i < m; i++) {
        cin >> first[i];
    }

    cin >> n;
    vector<int> second (n);
    for (int i = 0; i < n; i++) {
        cin >> second[i];
    }

    map<int, int> f = countingSort(first), s = countingSort(second);
    map<int, int> r = uniteTwoMaps(f, s);

    int m = INT_MAX;
    for (const auto &myPair : r) {
        if (myPair.second < m) {
            result[myPair.first] = myPair.second;
        }
    }

    return 0;
}

