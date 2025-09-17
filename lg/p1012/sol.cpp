/*
 * Problem: P1012 [NOIP 1998 提高组] 拼数
 * URL: https://www.luogu.com.cn/problem/P1012
 * Time Limit: 1000 ms
 * Memory Limit: 128 MB
 * Created: 2025-08-08 22:40:20
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(const string& a, const string& b)
{
    return a + b > b + a;   // 谁拼接在前能产生更大的结果，就让谁在前
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string num[20];
    for (int i = 0; i < n; i++) cin >> num[i];

    sort(num, num + n, cmp);
    string ans = num[0];
    for (int i = 1; i < n; i++) ans.append(num[i]);

    cout << ans;

    cout << endl;
    return 0;
}
