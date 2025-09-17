/*
 * Problem: C - Flush
 * URL: https://atcoder.jp/contests/abc418/tasks/abc418_c
 * Time Limit: 2000 ms
 * Memory Limit: 1024 MB
 * Created: 2025-08-09 21:17:00
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,q;
	cin>>n>>q;
	vector<int> av;
	for (int i=0;i<n;i++) {
		int a;
		cin>>a;
		av.push_back(a);
	}
	sort(av.begin(),av.end());
	vector<ll> ps(n);
	ps[0]=av[0];
	for (int i=1;i<n;i++)
		ps[i]=av[i]+ps[i-1];

	vector<ll> ans;

	for(int i=0;i<q;i++){
		ll b;
		cin>>b;
		if (b>av[n-1]){
			ans.push_back(-1);
			continue;
		}
		ll x=0;
		auto p=lower_bound(av.begin(),av.end(),b);
		if (p==av.begin()) ans.push_back(n*(b-1)+1);
		else if (p==av.end()) ans.push_back(ps[n-1]);
		else{
			x+=ps[(p-av.begin())-1]+(av.end()-p)*(b-1)+1;
			ans.push_back(x);
		}
	}
		
	for (auto a:ans)
		cout<<a<<'\n';

    return 0;
}
