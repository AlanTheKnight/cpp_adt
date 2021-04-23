#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
    long long dp[61][61][61];
    long long n, a0, b0, c0;
    cin >> n >> a0 >> b0 >> c0;

    for (int i = 0; i < 61; i++)
        for (int j = 0; j < 61; j++)
            for (int k = 0; k < 61; k++)
                dp[i][j][k] = LONG_LONG_MAX - 1;

    dp[a0][b0][c0] = n;

    for (int a = a0; a >= 0; a--)
        for (int b = b0; b >= 0; b--)
            for (int c = c0; c >= 0; c--) {
                if (a) dp[a - 1][b][c] = min(dp[a - 1][b][c], dp[a][b][c] / 2);
                if (b) dp[a][b - 1][c] = min(dp[a][b - 1][c], (dp[a][b][c] + 1) / 2);
                if (c) dp[a][b][c - 1] = min(dp[a][b][c - 1], (dp[a][b][c] - 1) / 2);
            }

    cout << dp[0][0][0] << endl;
    return 0;
}
