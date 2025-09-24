#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

ll dp[21][21][21];

void printw(ll a, ll b, ll c, ll ans)
{
    cout << "w(" << a << ", " << b << ", " << c << ") = " << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                dp[i][j][k] = 1;
            }
        }
    }

    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= 20; j++) {
            for (int k = 1; k <= 20; k++) {
                if (i < j && j < k)
                    dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] -
                                  dp[i - 1][j - 1][k - 1];
            }
        }
    }

    ll a, b, c;
    while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1)) {
        if (a <= 0 || b <= 0 || c <= 0) {
            printw(a, b, c, 1);
        } else if (a > 20 || b > 20 || c > 20) {
            printw(a, b, c, dp[20][20][20]);
        } else {
            printw(a, b, c, dp[a][b][c]);
        }
    }

    return 0;
}