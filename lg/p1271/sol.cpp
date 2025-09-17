/*
 * Problem: P1271 【深基9.例1】选举学生会
 * URL: https://www.luogu.com.cn/problem/P1271
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 16:39:11
 */

//计数排序
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin>>n>>m;

	vector<int> raw(m);
	vector<int> count(n+1,0);
	vector<int> ans(m);

	for (int i=0;i<m;i++){
		cin>>raw[i];
		count[raw[i]]++;
	}

	for (int i=2;i<=n;i++)
		count[i]+=count[i-1];

	for (int i=m-1;i>=0;i--)
		ans[--count[raw[i]]]=raw[i];

	for (int i=0;i<m;i++){
		if (i) cout<<' ';
		cout<<ans[i];
	}

	cout << endl;
    return 0;
}
