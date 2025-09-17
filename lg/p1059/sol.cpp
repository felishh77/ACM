/*
 * Problem: P1059 [NOIP 2006 普及组] 明明的随机数
 * URL: https://www.luogu.com.cn/problem/P1059
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 18:05:02
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	bool m[1001];
	fill(m,m+1001,false);

	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		if (m[k]) continue;
		m[k]=true;
	}

	vector<int> ans;
	int c=0;
	for (int i=1;i<1001;i++){
		if (m[i]){
			ans.push_back(i);
			c++;
		}
	}
	
	cout<<c<<'\n';
	for (int i=0;i<c;i++){
		if (i) cout<<' ';
		cout<<ans[i];
	}

	cout << endl;
    return 0;
}
