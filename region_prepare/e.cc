#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    long long k, x, y;
    cin >> k >> x >> y;
    long long lo = (y / x) * x; // минимальный суммарный вес пакетов
    long long hi = (y / x) * (x + k - 1); // максимальный суммарный вес пакетов
    long long ans = (lo <= y && y <= hi) ? y : x * (y / x + 1);
    cout << ans << endl;
    return 0;
}

