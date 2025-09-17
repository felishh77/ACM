/*
 * Problem: P1068 [NOIP 2009 普及组] 分数线划定
 * URL: https://www.luogu.com.cn/problem/P1068
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 21:28:41
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> P;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  priority_queue<P> list;

  for (int i = 0; i < n; i++) {
    int id, sc;
    cin >> id >> sc;
    list.push({sc, -id});
  }

  m = (m * 3) / 2;
  P mth;
  vector<P> ans;
  for (int i = 0; i < m; i++) {
    mth = list.top();
    list.pop();
    ans.push_back(mth);
  }
  int line = mth.first;
  while (!list.empty()) {
    mth = list.top();
    list.pop();
    if (mth.first < line)
      break;
    ans.push_back(mth);
  }

  cout << line << ' ' << ans.size() << '\n';
  for (auto a : ans)
    cout << -(a.second) << ' ' << a.first << '\n';

  cout << endl;
  return 0;
}
