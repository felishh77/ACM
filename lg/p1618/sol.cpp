/*
 * Problem: P1618 三连击（升级版）
 * URL: https://www.luogu.com.cn/problem/P1618
 * Time Limit: 1000 ms
 * Memory Limit: 128 MB
 * Created: 2025-08-10 17:08:02
 */

#include <algorithm>
#include <bits/stdc++.h>
#define ll long long
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

	vi n;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if(i==j) continue;
			for(int k=1;k<=9;k++){
				if(i==k||j==k) continue;
				n.push_back(i*100+j*10+k);
			}
		}
	}
	int a,b,c;
	cin>>a>>b>>c;
	if(!(a&&b&&c)){
		cout<<"No!!!"<<'\n';
		return 0;
	}
	bool found=false;
	for (auto itx=n.begin();itx!=n.end()&&(*itx)*b/a<=987;itx++) {
		bool used[10];
		fill(used,used+10,false);
		used[(*itx)/100]=used[((*itx)/10)%10]=used[(*itx)%10]=true;
		for (auto ity=itx+1; ity!=n.end()&&(*ity)*c/b<=987; ity++){
			if((*itx)*b!=(*ity)*a) continue;
			int y=*ity;bool rep=false;
			bool usedy[10];
			copy(used,used+10,usedy);
			while(y){
				if(usedy[y%10]){
					rep=true;
					break;
				}
				usedy[y%10]=true;
				y/=10;
			}
			if(rep)continue;
			for (auto itz=ity+1; itz!=n.end(); itz++) {
				int z=*itz;rep=false;
				bool usedz[10];
				copy(usedy,usedy+10,usedz);
				while(z){
					if(usedz[z%10]){
						rep=true;
						break;
					}
					usedz[z%10]=true;
					z/=10;
				}
				if(rep)continue;
				if((*ity)*c==(*itz)*b) {
					cout<<*itx<<' '<<*ity<<' '<<*itz<<'\n';
					found=true;
				}
			}
		}
	}
	if(!found) cout<<"No!!!"<<'\n';

    return 0;
}
