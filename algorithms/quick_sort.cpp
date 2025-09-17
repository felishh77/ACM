#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int a[10];

int part(int l,int r)
{
    int pivot=a[l];
    while(l<r){
        while(l<r&&a[r]>=pivot) r--;
        if(l<r) a[l++]=a[r];
        while(l<r&&a[l]<pivot) l++;
        if(l<r) a[r--]=a[l];
    }
    a[l]=pivot;
    return l;
}

void qs(int l,int r)
{
    if(l<r){
        int m=part(l, r);
        qs(l,m-1);
        qs(m+1,r);
    }
}

int main()
{
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(1,100);
    e.seed(time(0));

    cout<<"Original List: ";
    for(int i=0;i<10;i++) {
        a[i]=u(e);
        cout<<a[i]<<' ';
    }
    cout<<'\n'<<"After quick sort: ";

    qs(0,9);

    for(int i=0;i<10;i++) cout<<a[i]<<' ';
    cout<<endl;

}
