/*
 * Problem: P1255 数楼梯
 * URL: https://www.luogu.com.cn/problem/P1255
 * Time Limit: 1000 ms
 * Memory Limit: 128 MB
 * Created: 2025-09-08 19:12:35
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int n, len = 1, f[5003][5003];

void hplus(int k)
{
    int i;
    for (int i = 1; i <= len; i++) f[k][i] = f[k - 1][i] + f[k - 2][i];
    for (int i = 1; i <= len; i++)
        if (f[k][i] >= 10) {
            f[k][i + 1] += 1;
            f[k][i] %= 10;
        }
    if (f[k][len + 1]) len++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    f[1][1] = 1;
    f[2][1] = 2;
    for (int i = 3; i <= n; i++) hplus(i);
    for (int i = len; i >= 1; i--) cout << f[n][i];
    cout << '\n';

    return 0;
}
