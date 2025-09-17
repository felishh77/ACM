/*
 * Problem: P1706 全排列问题
 * URL: https://www.luogu.com.cn/problem/P1706
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-09-08 17:11:30
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int        temp[10];
bitset<11> vis;
void       arrange(int n, int p)
{
    if (p == n) {
        for (int i = 0; i < n; i++) cout << setw(5) << temp[i];
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vis.set(i);
        temp[p] = i;
        arrange(n, p + 1);
        vis.reset(i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    arrange(n, 0);

    return 0;
}
