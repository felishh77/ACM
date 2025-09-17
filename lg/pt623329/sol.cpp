/*
 * Problem: T623329 【MX-X16-T1】「DLESS-3」XOR and Greater Sum
 * URL: https://www.luogu.com.cn/problem/T623329?contestId=265699
 * Time Limit: 2000 ms
 * Memory Limit: 512 MB
 * Created: 2025-08-10 14:26:25
 */
#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pqi priority_queue<int>
#define pi pair<int, int>
#define qi queue<int, int>
#define si stack<int>

using namespace std;

int hiestdig(ll n)
{
    if (n == 0) return 0;
    int dig = 0;
    while (n != 0) {
        n >>= 1;
        dig++;
    }
    return dig;
}

void push(ll n, ll* hid)
{
    int i = hiestdig(n);
    if (i == 0) return;
    if (*(hid + i) != 0) {
        push(n ^ *(hid + i), hid);
        *(hid + i) = 0;
    }
    else {
        *(hid + i) = n;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        ll hid[32];
        fill(hid, hid + 32, 0);
        for (int j = 0; j < n; j++) {
            ll num;
            cin >> num;
            push(num, hid);
        }
        bool empty = true;
        for (int j = 0; j < 32; j++) {
            if (hid[j]) {
                empty = false;
                break;
            }
        }
        if (empty)
            cout << "No" << '\n';
        else
            cout << "Yes" << '\n';
    }

    return 0;
}
