/**************************************************************
    Problem: 1613
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:208 ms
    Memory:20916 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
using namespace std;
const int Maxn = 10010;
const int Maxm = 501;
int n , m ;
int f[Maxn][Maxm] , a[Maxn];
int main() {
    cin>>n>>m;
    for(int i=1; i<=n; ++i) {
        cin>>a[i];
        f[i][0] = max(f[i][0] , f[i-1][0]);
        for(int j=1; j<=m; ++j) {
            f[i][j] = f[i-1][j-1]+a[i];
            if(i >= j) {
                f[i][0] = max(f[i][0] , f[i-j][j]);
            }
        }
    }
    cout<<f[n][0];
}