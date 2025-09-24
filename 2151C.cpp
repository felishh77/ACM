#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int num[400001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        memset(num, 0, sizeof(num));
        int n;
        cin >> n;
        for (int i = 0; i < 2 * n; i++) cin >> num[i];

        ll res[2];
        res[0] = 0;
        res[1] = 0;
        for (int i = 0; i < 2 * n - 1; i += 2) res[0] += num[i + 1] - num[i];
        cout << res[0] << ' ';
        if (n > 1) {
            for (int i = 1; i < 2 * n - 2; i += 2) res[1] += num[i + 1] - num[i];
            res[1] += num[2 * n - 1] - num[0];
            cout << res[1] << ' ';
            for (int j = 3; j <= n; j++) {
                res[(j + 1) % 2] +=
                    (num[2 * n - j + 2] - num[j - 3] + num[2 * n - j + 1] - num[j - 2] +
                     num[2 * n - j + 1] - num[2 * n - j + 2] + num[j - 3] - num[j - 2]);
                cout << res[(j + 1) % 2] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}