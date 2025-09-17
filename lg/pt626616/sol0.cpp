/*
 * Problem: T626616 [IAMOI R2] 逻辑推理
 * URL: https://www.luogu.com.cn/problem/T626616?contestId=232936
 * Time Limit: 3250 ms
 * Memory Limit: 512 MB
 * Created: 2025-08-09 14:20:34
 */

#include <bits/stdc++.h>
#define ll long long
#define inf INT_MAX
using namespace std;
typedef pair<string, int> P;

struct rule
{
    int          l;
    int          ti;
    vector<char> r;
    queue<int>   op;
};

int minrt(vector<int>& list, vector<rule>& rules, int dst)
{
	//cout<<dst<<'\n';
	//for (auto l:list) cout<<l;
	//cout<<'\n';
	if (list[dst-1]==0) return 0;
    int ans       = inf;
    list[dst - 1] = -2;
    for (auto const &r : rules) {
        if (r.ti == dst) {
            queue<int> opc = r.op;
            stack<int> st;
            auto       i = r.r.begin();
            for (; i != r.r.end(); i++) {
                if (*i == 'o') {
                    int co = opc.front();
                    opc.pop();
                    if (list[co - 1] == -2)
                        st.push(-1);
                    else if (list[co - 1] == -1) {
                        int rst = minrt(list, rules, co);
                        if (rst == -1) st.push(-1);
						else{
							list[co - 1] = rst;
							st.push(list[co - 1]);
						}
                    }
                    else st.push(list[co - 1]);
                }
                else if (*i == '|') {
                    int oa = st.top();
                    st.pop();
                    int ob = st.top();
                    st.pop();
					if (oa>=0&&ob>=0) st.push(min(oa,ob));
					else if (oa>=0||ob>=0) st.push(max(oa,ob));
					else st.push(-1);
                }
                else {
                    int oa = st.top();
                    st.pop();
                    int ob = st.top();
                    st.pop();
                    if (oa>=0&&ob>=0) st.push(max(oa, ob));
					else st.push(-1);
                }
            }
            if (st.top()>=0) ans = min(ans, st.top());
        }
    }
    if (ans == inf)
        return -1;
    else{
		list[dst-1]=ans+1;
        return list[dst-1];
	}
}


vector<int> solve(int& n, int& m, vector<rule>& rules, vector<P>& qr)
{
    vector<int> ans;
    for (const auto& q : qr) {
        vector<int> list;
        for (int i = 0; i < n; i++) list.push_back(q.first[i] - '0' - 1);
        ans.push_back(minrt(list,rules,q.second));
		//cout<<'\n';
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int                 t;
	cin>>t;
    vector<vector<int>> ans;
    for (int i = 0; i < t; i++) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<rule> rules;
        vector<P>    qr;
        for (int j = 0; j < m; j++) {
            rule r0;
            cin >> r0.l >> r0.ti;
            for (int k = 0; k < r0.l; k++) {
                string s;
                cin >> s;
                if (s == "|")
                    r0.r.push_back('|');
                else if (s == "&")
                    r0.r.push_back('&');
                else {
                    r0.r.push_back('o');
                    r0.op.push(stoi(s.substr(1), 0, 10));
                }
            }
            rules.push_back(r0);
        }
        for (int j = 0; j < q; j++) {
            string s;
            int    t;
            cin >> s >> t;
            qr.push_back({s, t});
        }
        ans.push_back(solve(n, m, rules, qr));
		//cout<<'\n';
		
    }

    for (const auto& A : ans)
        for (auto a : A) cout << a << '\n';

    return 0;
}
