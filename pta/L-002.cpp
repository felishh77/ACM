#include <cmath>
#include <iostream>

using namespace std;

void printchar(int k, char c)
{
    for (int i = k; i >= 1; i -= 2) {
        for (int j = 0; j < ((k - i) / 2); j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << c;
        }
        cout << '\n';
    }
    for (int i = 3; i <= k; i += 2) {
        for (int j = 0; j < ((k - i) / 2); j++) {
            cout << ' ';
        }
        for (int j = 0; j < i; j++) {
            cout << c;
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char c;
    cin >> n >> c;
    // compute the largest odd k such that used = ((k+1)^2)/2 - 1 <= n
    int k = (int)floor(sqrt(2.0 * (n + 1))) - 1;
    if (k % 2 == 0) k--;
    while (k >= 1 && ((k + 1) * (k + 1)) / 2 - 1 > n) k -= 2;

    if (k >= 1) {
        printchar(k, c);
        int used = (int)((k + 1) * (k + 1) / 2 - 1);
        cout << (n - used) << '\n';
    } else {
        // not enough to print even the smallest sandglass
        cout << n << '\n';
    }
    return 0;
}