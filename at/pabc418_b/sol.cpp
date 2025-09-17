/*
 * Problem: B - You're a teapot
 * URL: https://atcoder.jp/contests/abc418/tasks/abc418_b
 * Time Limit: 2000 ms
 * Memory Limit: 1024 MB
 * Created: 2025-08-09 20:48:08
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	double ans=0.0;
	string raw;
	cin>>raw;

	int len=raw.length();
	int ptr1=0,ptr2;
	while (ptr1<len){
		while (ptr1<len&&raw[ptr1]!='t') ptr1++;
		if (ptr1<len){
			int ts=1;
			ptr2=ptr1+1;
			while (ptr2<len){
				while (ptr2<len&&raw[ptr2]!='t') ptr2++;
				if (ptr2<len){
					ts++;
					if (ptr2-ptr1>=2)
						ans=max(ans,(ts-2.0)/(ptr2-ptr1-1.0));
					ptr2++;
				}
			}
		}
		ptr1++;
	}

	cout<<fixed<<setprecision(17);
	cout<<ans;

	cout << endl;
    return 0;
}
