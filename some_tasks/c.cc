#include <iostream>
#include <cmath>


struct coord
{
    int x, y;
};


int main(int argc, char const *argv[])
{
    double result = 0;
    int n;
    std::cin >> n;
    coord data[n];
    for (int i = 0; i < n; i++) {
        coord c;
        std::cin >> c.x >> c.y;
        data[i] = c;
    }

    for (int i = 1; i < n; i++) {
        result += sqrt(
            pow(data[i].x - data[i-1].x, 2) + pow(data[i].y - data[i-1].y, 2)
        );
    }

    printf("%.6f", result);
    std::cout << std::endl;
    return 0;
}
