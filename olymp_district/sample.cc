#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int diff = min(n, m);
    int answer = diff * 2;
    if ((max(n, m) - diff) % 2)
        answer++;
    cout << answer << endl;
    return 0;
}


