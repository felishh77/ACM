/*
 * Problem: P1036 [NOIP 2002 普及组] 选数
 * URL: https://www.luogu.com.cn/problem/P1036
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-09-05 11:06:30
 */

#include <bits/stdc++.h>
#include <bitset>
#define ll long long
#define inf 0x3f3f3f3f
const int MAXN = 100000000;

using namespace std;

bitset<MAXN> is_prime;
int          num[20];
int          cnt = 0;

void dfs(int s, int n, int t, int sum)
{
    if (n == 0) {
        if (is_prime[sum]) cnt++;
        return;
    }
    for (int i = s; i <= t - n; i++) {
        dfs(i + 1, n - 1, t, sum + num[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; 1LL * i * i < MAXN; i++) {
        if (!is_prime[i]) continue;
        for (ll j = 1LL * i * i; j < MAXN; j += i) is_prime[j] = 0;
    }
    // cout << is_prime[97] << '\n';

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> num[i];

    dfs(0, k, n, 0);
    cout << cnt << '\n';

    return 0;
}
