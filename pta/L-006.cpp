#define _ALLOW_COMPILER_AND_STL_VERSION_MISMATCH 1
#include <iostream>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll bestLen = 0;
    ll bestStart = 0;

    for (int i = 2; i * i <= n; i++) {
        ll prod = 1;
        for (int j = i; prod * j <= n; j++) {
            prod *= j;
            if (n % prod == 0) {
                int len = j - i + 1;
                if (len > bestLen) {
                    bestLen = len;
                    bestStart = i;
                }
            } else
                break;
        }
    }

    if (bestLen == 0) {
        cout << 1 << '\n' << n << '\n';
        return 0;
    } else {
        cout << bestLen << '\n';
        for (ll i = 0; i < bestLen; i++) {
            if (i) cout << '*';
            cout << (bestStart + i);
        }
    }
    cout << '\n';
    return 0;
}