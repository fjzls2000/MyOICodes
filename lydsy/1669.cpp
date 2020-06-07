/**************************************************************
    Problem: 1669
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:28 ms
    Memory:1328 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
int n,a[5001],h[5001],ans;
int Search(int x) {
    int tmp,l=0,r=ans;
    while(l<=r) {
        int mid = (l+r)>>1;
        if(h[mid]<=x){tmp=mid;l=mid+1;}
        else r=mid-1;
    }
    return tmp;
}
int main() {
    memset(h,127,sizeof(h));
    cin>>n;
    for(int i=1; i<=n; ++i)
        cin>>a[i];
    h[0]=0;
    for(int i=1; i<=n; ++i) {
        int tmp=Search(a[i]);
        h[tmp+1]=min(h[tmp+1],a[i]);
        ans=max(ans,tmp+1);
    }
    printf("%d",ans);
}