/*
 * Problem: P2089 烤鸡
 * URL: https://www.luogu.com.cn/problem/P2089
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-09 13:25:15
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<array<int, 10>> ans;
array<int, 10>         ini;

void dfs(array<int, 10> a, int s, int k)
{
    if (s == 9) {
        if (k >= 0 && k <= 2) {
            a[s] += k;
            ans.push_back(a);
        }
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (i > k || k - i > 2 * (9 - s)) continue;
        a[s] = 1 + i;
        dfs(a, s + 1, k - i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ini.fill(1);
    dfs(ini, 0, n - 10);

    cout << ans.size() << '\n';
    for (const auto& a : ans) {
        for (auto i = a.begin(); i != a.end(); i++) {
            if (i != a.begin()) cout << ' ';
            cout << *i;
        }
        cout << '\n';
    }

    return 0;
}
