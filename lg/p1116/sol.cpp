/*
 * Problem: P1116 车厢重组
 * URL: https://www.luogu.com.cn/problem/P1116
 * Time Limit: 1000 ms
 * Memory Limit: 125 MB
 * Created: 2025-08-08 21:05:18
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int*> P;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int q[1000];
	for (int i=0;i<n;i++)
		q[i]=i;
	
	priority_queue<P,vector<P>,greater<P>> Q;
	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		Q.push({k,&q[i]});
	}

	int ans=0;
	while (!Q.empty()){
		P car=Q.top();Q.pop();
		ans+=*(car.second);
		for (int* i=car.second;i<q+n;i++)
			(*i)--;
	}

	cout<<ans;


	cout << endl;
    return 0;
}
