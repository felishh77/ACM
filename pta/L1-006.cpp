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

    for (ll i = 2; i * i <= n; i++) {
        ll t = n;
        ll j = i;
        while (t % j == 0) {
            t /= j;
            j++;
        }
        ll len = j - i;
        if (len > bestLen) {
            bestLen = len;
            bestStart = i;
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