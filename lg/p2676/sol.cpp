/*
 * Problem: P2676 [USACO07DEC] Bookshelf B
 * URL: https://www.luogu.com.cn/problem/P2676
 * Time Limit: 1000 ms
 * Memory Limit: 256 MB
 * Created: 2025-08-08 15:19:51
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,b;
	cin>>n>>b;
	priority_queue<int> h;
	for (int i=0;i<n;i++){
		int hi;
		cin>>hi;
		h.push(hi);
	}
	
	int s =0;
	int c=0;
	while (s<b){
		s+=h.top();
		h.pop();
		c++;
	}

	cout<<c;

	cout << endl;
    return 0;
}
