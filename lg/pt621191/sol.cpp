/*
 * Problem: T621191 【MX-X16-T2】「DLESS-3」XOR and Multiply
 * URL: https://www.luogu.com.cn/problem/T621191?contestId=265699
 * Time Limit: 2000 ms
 * Memory Limit: 512 MB
 * Created: 2025-08-10 15:25:09
 */

#include <bits/stdc++.h>
#define ll unsigned long long
#define vi vector<int>
#define pqi priority_queue<int>
#define pi pair<int,int>
#define qi queue<int,int>
#define si stack<int>

using namespace std;

int hid(ll n)
{
	if(n==0)return 0;
	int pos=0;
	while(n!=0){
		pos++;
		n>>=1;
	}
	return pos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		ll x; ll y; int h;
		cin>>x>>y>>h;
		if (x==y){
			cout<<(~(~0U<<h))*(~(~0U<<h))<<'\n';
		}
		else{
			ll xy=x^y;
			int hidg=hid(xy);
			int fcap=h-hidg;
			ll fhead= ~(~0U<<fcap)<<hidg;
			ll a=(fhead|xy)^~(~0U<<(hidg-1));
			ll b=(fhead|~(~0U<<(hidg-1)));
			ll res=a*b;
			cout<<(ll)res<<'\n';
		}
	}

    return 0;
}
