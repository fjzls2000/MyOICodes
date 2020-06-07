/**************************************************************
    Problem: 1191
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:2080 kb
****************************************************************/
 
#include<stdio.h>
#include <memory.h>
 
int n , m , to[100010] , next[100010] , g[100010] , ecnt = 0 , used[1010]; bool b[1010] , w[100010];
 
void ins( int a , int b ) { to[++ecnt] = b ; next[ecnt] = g[a]; g[a] = ecnt ; w[ecnt] = 1; to[++ecnt] = a ; next[ecnt] = g[b]; g[b] = ecnt; }
 
bool find(int x) {
    for(int i=g[x]; i; i=next[i]) {
        if(w[i] && !b[to[i]]) {
            b[to[i]] = 1;
            if(!used[to[i]] || find(used[to[i]])) {
                used[to[i]] = x;
                return 1;
            }
        }
    }return 0;
}
 
int main() {
    int a1 , b1 , ans = 0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; ++i) {
        scanf("%d%d",&a1,&b1);
        ins(i , b1); ins(i , a1);
    }
    for(ans = 1; ans<=m; ++ans) {
        memset(b , 0 , sizeof(b));
        if(!find(ans)) break;
    }printf("%d",ans-1);
}