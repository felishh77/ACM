#include <iostream>
using namespace std;

int main()
{
    long long res=0;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++) {
        res+=i;
    }
    cout<<res<<'\n';
    return 0;
}