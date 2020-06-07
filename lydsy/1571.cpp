/**************************************************************
    Problem: 1571
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:120 ms
    Memory:9228 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
const int Maxn = 10010;
const int Maxm = 101;
int n , m , k , f[Maxn][Maxm] , a , b , c , g[Maxn] , ke[Maxn][Maxm] , po[Maxm];
int main() {
    memset(f,128,sizeof(f));
    cin>>n>>m>>k;
    for(int i=1; i<=m; ++i) {
        cin>>a>>b>>c;
        ke[a+b-1][c] = max(ke[a+b-1][c] , a);
    }
    memset(po,42,sizeof(po));
    for(int i=1; i<=k; ++i) {
        cin>>a>>b;
        for(int j=a; j<=100; ++j) {
            po[j] = min(po[j] , b);
        }
    }
    f[0][1] = 0;
    g[0] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=100; ++j) {
            f[i][j] = f[i-1][j];
            if(ke[i-1][j]) f[i][j] = max(f[i][j] , g[ke[i-1][j]]);
            if(i-po[j] >= 0) f[i][j] = max(f[i][j] , f[i-po[j]][j] + 1);
            g[i] = max(g[i] , f[i][j]);
        }
    }
    cout<<g[n];
}