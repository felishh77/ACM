/*
 * Problem: P2241 统计方形（数据加强版）
 * URL: https://www.luogu.com.cn/problem/P2241
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-09 10:15:47
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ll s = 0;
    ll r = 0;

    int low = min(m, n);
    for (int i = 1; i <= low; i++) s += (m - i + 1) * (n - i + 1);

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) r += (m - i + 1) * (n - j + 1);

    r -= s;

    cout << s << ' ' << r << '\n';

    return 0;
}
