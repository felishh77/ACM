/*
 * Problem: A - I'm a teapot
 * URL: https://atcoder.jp/contests/abc418/tasks/abc418_a
 * Time Limit: 2000 ms
 * Memory Limit: 1024 MB
 * Created: 2025-08-09 20:41:09
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	if (n<3){
		cout<<"No"<<'\n';
		return 0;
	}

	string raw;
	cin>>raw;

	string tea=raw.substr(n-3);
	if (tea=="tea") cout<<"Yes";
	else cout<<"No";

	cout << endl;
    return 0;
}
