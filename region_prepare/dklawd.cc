#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FOR(I, TIMES) for (ll I = 0; I < TIMES; I++)
#define RANGE(I, START, END) for(ll I = START; I < END; I++)


int main(int argc, char const *argv[])
{
    int t; cin >> t;

    FOR(i, t) {
        ll n, m;
        cin >> n >> m;

        ll diff = LONG_LONG_MAX - 1;
        char diff_type = 'H';
        ll diff_index;
        ll total_sum = (1 + n * m) * (n * m) / 2;
        RANGE(h, 1, n) {
            ll s1 = (1 + m * h) * (m * h) / 2;
            ll s2 = abs(total_sum - s1);
            diff = min(abs(s1 - s2), diff);
            if (diff == abs(s1 - s2)) {
                diff_index = h;
            }
        }
        RANGE(v, 1, m) {
            ll s1 = n * v * (1 + v + m * (n - 1)) / 2;
            ll s2 = abs(total_sum - s1);
            diff = min(abs(s1 - s2), diff);
            if (diff == abs(s1 - s2)) {
                diff_index = v;
                diff_type = 'V';
            }
        }
        cout << diff_type << ' ' << diff_index + 1 << endl;
    }

    return 0;
}

