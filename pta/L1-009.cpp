#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push({x, y});
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i].second;
    }
    cout << '\n';

    return 0;
}