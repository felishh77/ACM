/*
 * Problem: P1036 [NOIP 2002 普及组] 选数
 * URL: https://www.luogu.com.cn/problem/P1036
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-09-02 21:52:13
 */

#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int num[20];

vector<ll> comb_add(int start, int n, int t)
{
    vector<ll> result;
    if (n == 1) {
        for (int i = start; i < t; i++) result.push_back(num[i]);
        return result;
    }
    for (int i = start; i <= t - n; i++) {
        auto res2 = comb_add(i + 1, n - 1, t);
        for (auto s : res2) result.push_back(num[i] + s);
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool is_prime[100000000];
    fill(is_prime, is_prime + 100000000, true);
    is_prime[1] = false;
    for (int i = 2; i < 10000; i++) {
        if (!is_prime[i]) continue;
        for (ll j = 2 * i; j < 100000000; j += i) is_prime[j] = false;
    }

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> num[i];

    int        cnt      = 0;
    vector<ll> sum_list = comb_add(0, k, n);
    for (auto s : sum_list)
        if (is_prime[s]) cnt++;

    cout << cnt << '\n';

    return 0;
}
