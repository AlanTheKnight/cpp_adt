#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    long long n, k, x, y;
    cin >> n >> k >> x >> y;

    int parad = x * (n / k) + y * (n - n / k);
    int block = y * (k - 1) + x;

    cout << parad << ' ' << block << endl;

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        long long t; cin >> t;
        t = (t - 1) % parad + 1;
        long long blocks = t / block;
        t %= block;
        long long p = 0;
        p = (t + y - 1) / y;
        if (p > k - 1) p = k;
        cout << blocks * k + p << endl;
    }

    return 0;
}

