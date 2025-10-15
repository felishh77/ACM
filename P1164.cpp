#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int a[102];

int dfs(int k, int n, int m) {
    if (m == 0) return 1;
    int res = 0;
    for (int i=k; i<=n; i++) {
        if (a[i] > m) continue;
        res += dfs(i+1, n, m-a[i]);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) cin >> a[i];
    cout << dfs(0, n, m) << '\n';

    return 0;
}