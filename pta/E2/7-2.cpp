#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll fib[3];
    fib[0] = 1;
    fib[1] = 1;

    int n;
    cin >> n;

    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    cout << 1 << ' ' << 1;
    for (int i = 2; i < n; i++) {
        fib[i % 3] = fib[(i + 1) % 3] + fib[(i + 2) % 3];
        cout << ' ' << fib[i % 3];
    }

    cout << '\n';

    return 0;
}