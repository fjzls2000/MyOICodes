/**************************************************************
    Problem: 1603
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:3240 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
using namespace std;
const int Maxn = 100010;
int n , to[Maxn] , next[Maxn] , g[Maxn] , f[Maxn] , w[Maxn] , ecnt = 0;
 
void ins(int a , int b , int c) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
    w[ecnt] = c;
}
 
void dfs(int x) {
    for(int i=g[x]; i; i=next[i]) {
        f[to[i]] = f[x]^w[i];
        dfs(to[i]);
    }
}
 
int main() {
    scanf("%d",&n);
    for(int i=1; i<n; ++i) {
        int a , b , c;
        scanf("%d%d%d",&a,&b,&c);
        ins(a,b,c);
    }
    dfs(1);
    printf("%d\n", f[n]);
}