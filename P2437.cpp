#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

// 高精度加法模板
string add(string a, string b) {
  string result = "";
  int carry = 0; // 进位

  // 从个位开始相加
  int i = a.length() - 1;
  int j = b.length() - 1;

  while (i >= 0 || j >= 0 || carry > 0) {
    int sum = carry;
    if (i >= 0) {
      sum += a[i] - '0';
      i--;
    }
    if (j >= 0) {
      sum += b[j] - '0';
      j--;
    }

    result = char(sum % 10 + '0') + result; // 当前位
    carry = sum / 10;                       // 进位
  }

  return result;
}

string path[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int m, n;
  cin >> m >> n;

  path[1] = "1";
  path[2] = "1";
  for (int i = 3; i <= n; i++) {
    path[i] = add(path[i - 1], path[i - 2]);
  }
  cout << path[n - m + 1] << endl;

  return 0;
}