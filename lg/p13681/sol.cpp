/*
 * Problem: P13681 [IAMOI R2] 逻辑推理
 * URL: https://www.luogu.com.cn/problem/P13681?contestId=232936
 * Time Limit: 3250 ms
 * Memory Limit: 512 MB
 * Created: 2025-08-09 22:18:37
 */

#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;

struct rule
{
	int dst;
	vector<int> expr;
};

bool calc(vector<bool> &stat,vector<int> &expr)
{
	stack<bool> st;
	for(auto op=expr.begin();op!=expr.end();op++){
		//cout<<*op<<' ';
		if(*op==-1){//'|'
			bool op1=st.top();st.pop();
			bool op2=st.top();st.pop();
			st.push(op1||op2);
		}
		else if(*op==-2){//'&'
			bool op1=st.top();st.pop();
			bool op2=st.top();st.pop();
			st.push(op1&&op2);
		}
		else
			st.push(stat[*op]);
	}
	//cout<<'\n';
	return st.top();
}

int solve(int dst,vector<rule> &rules,vector<bool> &stat)
{
	//cout<<dst<<' ';
	//cout<<stat[dst]<<' ';
	if (stat[dst]) return 0;
	int ans=inf;
	for(auto ite=rules.begin();ite!=rules.end();ite++){
		if(calc(stat,ite->expr)){
			vector<bool> stat_temp=stat;
			vector<rule> rules_temp=rules;
			stat_temp[ite->dst]=true;
			rules_temp.erase(rules_temp.begin()+(ite-rules.begin()));
			int rec=solve(dst,rules_temp,stat_temp);
			if(rec!=-1) ans=min(ans,rec);
		}
	}
	if(ans==inf) return -1;
	return ans+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int n,m,q;
		cin>>n>>m>>q;
		vector<rule> rules;
		for(int j=0;j<m;j++){
			int s,dst;
			cin>>s>>dst;
			rule r;
			vector<int> expr;
			for(int k=0;k<s;k++){
				string op;
				cin>>op;
				if(op=="|") expr.push_back(-1);
				else if(op=="&") expr.push_back(-2);
				else expr.push_back(stoi(op.substr(1),0,10));
			}
			r.dst=dst;r.expr=expr;
			rules.push_back(r);
		}
		for(int j=0;j<q;j++){
			vector<rule> rules_cp=rules;
			string raw;
			vector<bool> stat;
			stat.push_back(false);
			int dst;
			cin>>raw>>dst;
			for(int k=0;k<n;k++) stat.push_back((raw[k]=='1')?true:false);
			cout<<solve(dst,rules_cp,stat)<<'\n';
		}
	}
    return 0;
}
