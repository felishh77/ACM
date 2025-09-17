/*
 * Problem: P1177 【模板】排序
 * URL: https://www.luogu.com.cn/problem/P1177
 * Time Limit: 1000 ms
 * Memory Limit: 256 MB
 * Created: 2025-08-08 17:08:20
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	priority_queue<ll, vector<ll>, greater<ll>> a;
	for (int i=0;i<n;i++){
		ll k;
		cin>>k;
		a.push(k);
	}

	for (int i=0;i<n;i++){
		if (i) cout<<' ';
		cout<<a.top();
		a.pop();
	}

	cout << endl;
    return 0;
}
