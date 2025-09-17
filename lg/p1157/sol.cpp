/*
 * Problem: P1157 组合的输出
 * URL: https://www.luogu.com.cn/problem/P1157
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-09-07 16:02:34
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int temp[20];

void dfs(int s, int n, int k, int* ptr)
{
    if (k == 0) {
        for (int* p = temp; p < ptr; p++) {
            cout << setw(3) << *p;
        }
        cout << '\n';
        return;
    }
    for (int i = s; i <= n - k + 1; i++) {
        *ptr = i;
        dfs(i + 1, n, k - 1, ptr + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    dfs(1, n, k, temp);

    return 0;
}
