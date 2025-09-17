/*
 * Problem: P3156 【深基15.例1】询问学号
 * URL: https://www.luogu.com.cn/problem/P3156
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-09-08 17:38:16
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

ll num[2000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> num[i];

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        cout << num[q - 1] << '\n';
    }

    return 0;
}
