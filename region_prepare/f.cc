#include <stack>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(I, TIMES) for (int I = 0; I < TIMES; I++)
#define FOR_RANGE(I, START, END) for (int I = START; I < END; I++)
#define FOR_AUTO(I, OBJ) for (auto I : OBJ)
#define DIV_UP(A, B) (A + B - 1) / B


int main(int argc, char const *argv[])
{
    int n; cin >> n;

    stack<int> positrons;
    vector<int> times;

    FOR(i, n) {
        int v, e;
        cin >> v >> e;
        if (e == 1) positrons.push(v);
        else {
            if (!positrons.empty()) {
                int positron = positrons.top();
                positrons.pop();
                times.push_back(DIV_UP(abs(positron - v), 2));
            }
        }
    }

    int t; cin >> t;
    FOR (i, t) {
        // Вывод ответа
    }

    FOR_AUTO(i, times) {
        cout << i << endl;
    }

    return 0;
}


