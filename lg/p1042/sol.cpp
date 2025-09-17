// Source: lg
// Problem: p1042
// Author: felix07
// Created: Thu Aug  7 17:03:27 CST 2025

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<array<int, 2>> m1;
    vector<array<int, 2>> m2;
    m1.push_back({0, 0});
    m2.push_back({0, 0});

    char c;
    while ((c = cin.get()) != 'E') {
        auto& s1 = m1.back();
        auto& s2 = m2.back();
        switch (c) {
            case 'W':
                if (++s1[0] >= 11 && s1[0] - s1[1] >= 2) m1.push_back({0, 0});
                if (++s2[0] >= 21 && s2[0] - s2[1] >= 2) m2.push_back({0, 0});
                break;
            case 'L':
                if (++s1[1] >= 11 && s1[1] - s1[0] >= 2) m1.push_back({0, 0});
                if (++s2[1] >= 21 && s2[1] - s2[0] >= 2) m2.push_back({0, 0});
                break;
            default:
                break;
        }
    }

    for (auto m : m1) cout << m[0] << ':' << m[1] << '\n';
    cout << '\n';
    for (auto m : m2) cout << m[0] << ':' << m[1] << '\n';

    return 0;
}
