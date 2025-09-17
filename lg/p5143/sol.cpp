/*
 * Problem: P5143 攀爬者
 * URL: https://www.luogu.com.cn/problem/P5143
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 21:51:47
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct P {
  int x, y, z;
};

bool operator>(P p1, P p2) { return p1.z > p2.z; }

double d(double x1, double y1, double z1, double x2, double y2, double z2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<P, vector<P>, greater<P>> que;

  for (int i = 0; i < n; i++) {
    P p;
    cin >> p.x >> p.y >> p.z;
    que.push(p);
  }

  double dis = 0.0;
  P cp = que.top();
  que.pop();
  while (!que.empty()) {
    P np = que.top();
    que.pop();
    dis += d(cp.x, cp.y, cp.z, np.x, np.y, np.z);
    cp = np;
  }

  cout << fixed << setprecision(3);
  cout << dis;

  cout << endl;
  return 0;
}
