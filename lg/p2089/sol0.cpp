/*
 * Problem: P2089 烤鸡
 * URL: https://www.luogu.com.cn/problem/P2089
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-09 10:39:45
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<array<int, 10>> a;

bool update(array<int, 10>& b)
{
    for (auto i = b.rbegin(); i + 1 != b.rend(); i++) {
        if (*i > 1 && *(i + 1) < 3) {
            (*i)--;
            (*(i + 1))++;
            a.push_back(b);
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    array<int, 10> raw;
    raw.fill(1);

    if (n < 10 || n > 30) {
        cout << 0 << '\n';
        return 0;
    }
    else if (n == 10)
        a.push_back(raw);
    else {
        int q = (n - 10) / 2;
        int r = n % 2;
        int i;
        for (i = 0; i < q; i++) raw[i] = 3;
        if (r) raw[i] = 2;
        reverse(raw.begin(), raw.end());
        a.push_back(raw);
    }

    while (update(raw));

    cout << a.size() << '\n';
    for (auto k : a) {
        for (auto i = k.begin(); i != k.end(); i++) {
            if (i != k.begin()) cout << ' ';
            cout << *i;
        }
        cout << '\n';
    }

    return 0;
}
