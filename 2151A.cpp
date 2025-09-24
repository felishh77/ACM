#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k, res = 0;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];
        k = a[0];
        for (int i = 1; i < m; i++) {
            if (a[i] == k + 1)
                k++;
            else {
                res = 1;
                break;
            }
        }
        if (!res) res = n - k + 1;
        cout << res << '\n';
    }

    return 0;
}