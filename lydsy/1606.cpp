/**************************************************************
    Problem: 1606
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:308 ms
    Memory:1356 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
using namespace std;
int c,h,a[5001];bool f[50001];
int main() {
    scanf("%d%d",&c,&h);
    for(int i=1;i<=h;i++)scanf("%d",&a[i]);
    f[0]=1;
    for(int i=1; i<=h; ++i)
        for(int j=c; j>=a[i]; --j)
            if(f[j-a[i]]) f[j] = 1;
    for(int i=c; i>=0; --i)
        if(f[i]) {
            printf("%d\n",i );
            break;
        }
    return 0;
}