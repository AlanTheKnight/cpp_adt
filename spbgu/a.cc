#include <iostream>
using namespace std;


int main() {
    int h , t , a , b , c;
    cin >> h >> t >> a >> b >> c;

    // h - головы
    // t - хвосты
    // a - вырастает голов
    // b - вырастает хвостов
    // c - сколько отростков отрубает меч

    if ((a >= c && h > c) || (c > h + t && h + t)) {
        cout << -1 << endl;
        return 0; 
    }

    int e = 0;
    
    while (true) {
        h -= c; // Герой отрубает голову
        if (h < 1) { // Дракон повержен!
            break;
        }
        h += a; // О нет! Головы отрастают!
        e += 1; // *кусь*
        if (c > h + t && h + t) {
            e = -1;
            break;
        }
    }

    cout << e << endl;
    return 0;
}

