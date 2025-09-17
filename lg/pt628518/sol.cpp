/*
 * Problem: T628518 【MX-X16-T3】「DLESS-3」XOR and Impossible Problem
 * URL: https://www.luogu.com.cn/problem/T628518?contestId=265699
 * Time Limit: 2000 ms
 * Memory Limit: 512 MB
 * Created: 2025-08-10 16:40:02
 */

#include <bits/stdc++.h>
#define ull unsigned long long
#define vi vector<int>
#define pqi priority_queue<int>
#define pi pair<int,int>
#define qi queue<int,int>
#define si stack<int>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--) {
		int n;
		cin >> n;
		vector<ull> vec(n);
		for (int j=0; j<n;j++) cin>>vec[j];
		ull ans=1;
		for (int s=0;s<n-1;s++) {
			for (int t=s+1; t<n; t++)
				ans*=vec[s]^vec[t];
		}
		cout<<ans<<'\n';
	}

    return 0;
}
