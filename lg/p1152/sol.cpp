/*
 * Problem: P1152 欢乐的跳
 * URL: https://www.luogu.com.cn/problem/P1152
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 16:29:32
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<ll> t;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		t.push_back(k);
	}
	
	bool jolly=true;
	vector<bool> st(n,false);
	for (int i=0;i<n-1;i++){
		int d=abs(t[i]-t[i+1]);
		if (d==0||d>=n||st[d]){
			jolly=false;
			break;
		}
	}
	
	if (jolly) cout<<"Jolly";
	else cout<<"Not jolly";

	cout << endl;
    return 0;
}
