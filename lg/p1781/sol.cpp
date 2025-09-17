/*
 * Problem: P1781 宇宙总统
 * URL: https://www.luogu.com.cn/problem/P1781
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 20:30:18
 */
#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(const pair<string,int>& a, const pair<string,int>& b) const {
        if (a.first.length() != b.first.length())
            return a.first.length() < b.first.length(); // 长度短的优先
        return a.first < b.first; // 字典序小的优先
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> vote;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vote.push({s, i+1});
    }

    auto pre = vote.top();
    cout << pre.second << '\n' << pre.first << '\n';
    return 0;
}

