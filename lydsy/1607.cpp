/**************************************************************
    Problem: 1607
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1156 ms
    Memory:9492 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int n , mx;
const int Maxn = 100010;
const int Maxm = 1000005;
int a[Maxn] , cnt[Maxm] , s[Maxm];
int main() {
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        ++cnt[a[i]];
        mx = max(mx , a[i]);
    }
    for(int i=1; i<=mx; ++i) {
        if(cnt[i])
            for(int j = i; j<=mx; j+=i)
                s[j] += cnt[i];
    }
    for(int i=1; i<=n; ++i)
        printf("%d\n",s[a[i]] - 1 );
    return 0;
}