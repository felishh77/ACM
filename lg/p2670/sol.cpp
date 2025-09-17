// Source: lg
// Problem: p2670
// Author: felix07
// Created: Thu Aug  7 17:57:15 CST 2025

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    char map[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char t;
            cin >> t;
            map[i][j] = (t == '*') ? 1 : 0;
        }
    }

    int ans[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
			if (map[i][j]==1){
				ans[i][j]=-1;
				continue;
			}
			ans[i][j]=0;
            for (int s = -1; s <= 1; s++)
                for (int t = -1; t <= 1; t++){
					if ((i+s<0||i+s>=n)||(j+t<0||j+t>=m)) continue;
                    ans[i][j] += map[min(max(i + s, 0), n - 1)][min(max(j + t, 0), m - 1)];
				}
		}

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
			if (ans[i][j]==-1) cout << '*';
            else cout << ans[i][j];
        }
        cout << '\n';
    }

    return 0;
}
