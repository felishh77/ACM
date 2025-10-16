#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll nums[5];
    ll s = 0;
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
        s += nums[i];
    }
    sort(nums, nums + 5);
    double a = (double)s / 5.0;

    cout << "Sum = " << s << ", Average = " << fixed << setprecision(2) << a << '\n';
    cout << "Max = " << nums[4] << '\n';

    return 0;
}