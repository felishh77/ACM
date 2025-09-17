/*
 * Problem: P1923 【深基9.例4】求第 k 小的数
 * URL: https://www.luogu.com.cn/problem/P1923
 * Time Limit: 1000 ms
 * Memory Limit: 250 MB
 * Created: 2025-08-08 17:19:36
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a;

ll part(int k,int l,int r)
{
	int s=l;
	int e=r;
	int p=a[l];
	while (l<r){
		while (l<r&&a[r]>=p) r--;
		a[l]=a[r];
		while (l<r&&a[l]<=p) l++;
		a[r]=a[l];
	}
	a[l]=p;
	if (l==k) return a[l];
	else if (l<k) return part(k,l+1,e);
	else return part(k,s,l-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	for (int i=0;i<n;i++){
		ll s;
		cin>>s;
		a.push_back(s);
	}
	
	cout<<part(k,0,n-1);

	cout << endl;
    return 0;
}
