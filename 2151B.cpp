#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> initial_black(m);
        for (int i = 0; i < m; i++) cin >> initial_black[i];

        set<int> black_cells(initial_black.begin(), initial_black.end());

        // Process each prefix length
        for (int i = 1; i <= n; i++) {
            int pos = 1;  // Always start from position 1

            // Execute first i commands
            for (int j = 0; j < i; j++) {
                if (s[j] == 'A') {
                    pos++;
                } else {  // s[j] == 'B'
                    // Find next white cell using binary search
                    auto it = black_cells.upper_bound(pos);
                    if (it != black_cells.end() && *it == pos + 1) {
                        // Skip consecutive black cells
                        pos = *it;
                        while (it != black_cells.end() && *it == pos) {
                            pos++;
                            it++;
                        }
                    } else {
                        pos++;
                    }
                }
            }

            // Color the final position black
            black_cells.insert(pos);
        }

        cout << black_cells.size() << '\n';
        bool first = true;
        for (int cell : black_cells) {
            if (!first) cout << ' ';
            cout << cell;
            first = false;
        }
        cout << '\n';
    }

    return 0;
}