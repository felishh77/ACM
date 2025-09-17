/*
 * Problem: P1093 [NOIP 2007 普及组] 奖学金
 * URL: https://www.luogu.com.cn/problem/P1093
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 18:31:13
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct stu
{
	int id;
	int s;
	int a,b,c;
};

bool operator<(stu x, stu y)
{
	if (x.s!=y.s) return x.s<y.s;
	else{
		if (x.a!=y.a) return x.a<y.a;
		else return x.id>y.id;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin>>n;
	priority_queue<stu> l;
	for (int i=1;i<=n;i++){
		stu s;
		s.id=i;
		cin>>s.a>>s.b>>s.c;
		s.s=s.a+s.b+s.c;
		l.push(s);
	}

	for (int i=0;i<5;i++){
		stu s=l.top();l.pop();
		cout<<s.id<<' '<<s.s<<'\n';
	}

    return 0;
}
