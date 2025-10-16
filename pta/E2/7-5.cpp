    #include <bits/stdc++.h>
    #define ll long long
    #define inf 0x3f3f3f3f

    using namespace std;

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        ll nums[5];
        for (int i=0; i<5; i++) {
            cin>>nums[i];
        }
        for (int i=4; i>=0; i--) {
            if(i<4) cout<<' ';
            cout<<nums[i];
        }
        cout<<'\n';

        return 0;
    }