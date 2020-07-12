#include <bits/stdc++.h>
using namespace std;

/*
Находит налог на грибы, яблоки, мёд или Машу
*/
int getTax(double amount) {
    double tax = floor(amount / 10);
    return tax;
}

/*
Находит налог на налог
*/
int getFinalTaxForTax(double *taxes) {
    // 
    double s;
    for (int i = 0; i < 4; i++) {
        s += taxes[i];
    }
    return getTax(s);
}

/*
Находит максимальное значение в массиве taxes
*/
int findMax(double *taxes) {
    int m = -1;
    for (int i = 0; i < 5; i++) {
        if (taxes[i] > m) {
            m = taxes[i];
        }
    }
    return m;
}

/*
Выводит гистограмму с ответом
*/
void print(double *taxes) {
    int height = findMax(taxes);
    int width = 5;
    vector<vector<char>> diagram(height, vector<char> (width));
    
    for (int j = 0; j < width; j++) {w
        int spaces = height - taxes[j];
        for (int i = 0; i < height; i++) {
            if (spaces > 0) {
                diagram[i][j] = ' ';
                spaces--;
            } else {
                diagram[i][j] = '*';
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << diagram[i][j];
        }
        cout << '\n';
    }
}

int main() {
    double taxes[5];
    for (int i = 0; i < 4; i++) {
        double amount;
        cin >> amount;
        taxes[i] = getTax(amount);
    }
    taxes[4] = getFinalTaxForTax(taxes);
    print(taxes);
    return 0;
}
