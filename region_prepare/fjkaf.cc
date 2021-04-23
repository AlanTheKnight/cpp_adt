#include <iostream>

typedef unsigned long long ull;

struct Pair
{
    ull x, y;
};

Pair quad_diff(ull n)
{
    if ((n % 4 == 2) || (n == 1) || (n == 4))
        return {0, 0};
    if (!(n % 4))
        return {n / 4 + 1, n / 4 - 1};
    if (n % 2 == 1)
        return {n / 2 + 1, n / 2};
    return {0, 0};
}

int main()
{
    ull n;
    std::cin >> n;
    Pair xy = quad_diff(n);
    if (xy.x)
        std::cout << "Yes" << std::endl
                  << xy.x << " " << xy.y << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}