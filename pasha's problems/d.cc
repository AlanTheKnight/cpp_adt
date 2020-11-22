#include <iostream>
#include <string>
#include <map>
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<string, int> posts;
    string biggest; int m = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        posts[s] = 0;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        if (posts.count(s) != 0) {
            posts[s]++;
            if (posts[s] > m) {
                biggest = s;
                m = posts[s];
            }
        }
    }

    cout << biggest << std::endl;
    return 0;
}

