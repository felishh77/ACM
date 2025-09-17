// Source: lg
// Problem: p1563
// Author: felix07
// Created: Thu Aug  7 19:24:31 CST 2025

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int n, m;
	cin>>n>>m;
	vector<int> d;//directions
	vector<string> p;//professionals
	vector<int> t;//instructions
	for(int i=0;i<n;i++){
		int a;
		string s;
		cin>>a>>s;
		d.push_back((a==0)?1:-1);
		p.push_back(s);
	}
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		t.push_back((a==1)?b:-b);
	}

	int c=0;
	for (auto ins=t.begin();ins!=t.end();ins++)
		c=(c+n+d[c]*(*ins))%n;
	
	cout<<p[c]<<'\n';

    return 0;
}
