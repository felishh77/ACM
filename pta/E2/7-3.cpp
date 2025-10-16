#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define MAXN 1000001

using namespace std;

bitset<MAXN> is_prime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    is_prime.set();
    is_prime.reset(1);
    for (int i = 2; i * i <= MAXN; i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i * i; j <= MAXN; j *= i) {
            is_prime.reset(j);
        }
    }

    int n;
    cin >> n;
    if (is_prime[n]) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }

    return 0;
}