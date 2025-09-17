/*
 * Problem: P1104 生日
 * URL: https://www.luogu.com.cn/problem/P1104
 * Time Limit: 1000 ms
 * Memory Limit: 128 MB
 * Created: 2025-08-09 10:00:50
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct B
{
    string n;
    int    y, m, d;
    int    id;
};

bool cmp(B a, B b)
{
    if (a.y == b.y) {
        if (a.m == b.m) {
            if (a.d == b.d) return a.id > b.id;
            return a.d < b.d;
        }
        return a.m < b.m;
    }
    return a.y < b.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    B b[100];
    for (int i = 0; i < n; i++) {
        b[i].id = i;
        cin >> b[i].n >> b[i].y >> b[i].m >> b[i].d;
    }

    sort(b, b + n, cmp);
    for (int i = 0; i < n; i++) cout << b[i].n << '\n';

    return 0;
}
