#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  stack<int> num_ops;
  deque<string> str_ops;
  string res;

  char c;
  string str_temp;
  int num_temp = 0;
  while ((c = getchar()) != EOF && c != '\n') {
    if (c == '[') {
      if (!str_temp.empty()) {
        str_ops.push_back(str_temp);
        str_temp.clear();
      }
      if (num_temp) {
        num_ops.push(num_temp);
        num_temp = 0;
      }
    } else if (c >= '0' && c <= '9')
      num_temp = num_temp * 10 + (int)(c - '0');
    else if (c >= 'A' && c <= 'Z') {
      if (num_temp) {
        num_ops.push(num_temp);
        num_temp = 0;
      }
      str_temp += c;
    } else if (c == ']') {
      // cout << "Before ]: " << str_temp << endl;
      int num = 1;
      if (!num_ops.empty()) {
        num = num_ops.top();
        num_ops.pop();
      }
      string str2;
      if (!str_ops.empty()) {
        str2 = str_ops.back(); // the previous string
        str_ops.pop_back();
      }
      // cout << str2 << ' ' << str_temp << ' ' << num << endl;
      for (int i = 0; i < num; i++)
        str2 += str_temp;
      str_temp = str2;
      // cout << str_temp << endl;
    }
  }

  cout << str_temp << '\n';

  return 0;
}