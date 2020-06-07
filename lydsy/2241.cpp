/**************************************************************
    Problem: 2241
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:104 ms
    Memory:884 kb
****************************************************************/
 
#include <stdio.h>
int sum ,  n , m , map[101][101] , t[101][101];
bool check(int x , int y) {
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            t[i][j] = map[i][j];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(t[i][j])
                if(i+x>n+1||j+y>m+1) return 0;
                else {
                    int kk = t[i][j];
                    for(int p=0; p<x; ++p)
                        for(int pp=0; pp<y; ++pp)
                            if(t[i+p][j+pp] < kk) return 0;
                            else t[i+p][j+pp]-=kk;
                }
    return 1;
}
int main() {
    int ans = 214748364;
    scanf("%d%d",&n,&m);
    for(register int i=1; i<=n; ++i)
        for(register int j=1; j<=m; ++j)
            scanf("%d",&map[i][j]) , sum+=map[i][j];
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(!(sum%(i*j)) && sum/i/j < ans)
                if(check(i , j)) ans = sum/i/j;
    printf("%d",ans);
}