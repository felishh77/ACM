#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

ll dp[1005];

ll cnt(int n)
{
    if (dp[n] != 0) return dp[n];

    ll ans = 1; 
    for (int i = 1; i <= n / 2; i++) {
        ans += cnt(i);
    }

    return dp[n] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << cnt(n) << endl;

    return 0;
}