/**************************************************************
    Problem: 1609
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:20 ms
    Memory:3240 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
using namespace std;
const int Maxn = 100010;
int n , a[Maxn] , f[Maxn][4];
int main() {
    cin>>n;
    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        f[i][1] = f[i-1][1] + (a[i] != 1);
        f[i][2] = min(f[i-1][2] , f[i-1][1]) + (a[i] != 2);
        f[i][3] = min(f[i-1][1] , min(f[i-1][2] , f[i-1][3])) + (a[i] != 3);
    }
    int ans = min(f[n][1] , min(f[n][2] , f[n][3]));
    for(int i=n; i; --i) {
        f[i][1] = f[i+1][1] + (a[i] != 1);
        f[i][2] = min(f[i+1][2] , f[i+1][1]) + (a[i] != 2);
        f[i][3] = min(f[i+1][1] , min(f[i+1][2] , f[i+1][3])) + (a[i] != 3);
    }
    int ans2 = min(f[1][1] , min(f[1][2] , f[1][3]));
    cout<<min(ans , ans2);
}