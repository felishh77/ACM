/*
 * Problem: P1002 [NOIP 2002 普及组] 过河卒
 * URL: https://www.luogu.com.cn/problem/P1002
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-09-17 08:36:07
 */

#include <bits/stdc++.h>
#include <cstring>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

struct P
{
    int x, y;
};

ll dp[21][21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));
    dp[0][0]                 = 1;
    vector<pair<int, int>> m = {
        {0, 0}, {2, 1}, {1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {-2, -1}, {-1, -2}};

    P s, h;
    cin >> s.x >> s.y >> h.x >> h.y;

    for (auto move : m) {
        int dx = h.x + move.first;
        int dy = h.y + move.second;
        if (dx >= 0 && dx <= s.x && dy >= 0 && dy <= s.y) dp[dx][dy] = -1;
    }

    for (int i = 1; i <= s.x; i++) {
        if (dp[i][0] == -1) break;
        dp[i][0] = 1;
    }

    for (int i = 1; i <= s.y; i++) {
        if (dp[0][i] == -1) break;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= s.y; i++) {
        for (int j = 1; j <= s.x; j++) {
            if (dp[i][j] == -1) continue;
            if (dp[i - 1][j] != -1) dp[i][j] += dp[i - 1][j];
            if (dp[i][j - 1] != -1) dp[i][j] += dp[i][j - 1];
        }
    }

    cout << dp[s.x][s.y] << '\n';

    return 0;
}
