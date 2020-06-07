/**************************************************************
    Problem: 1625
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:132 ms
    Memory:1196 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 100010; int f[Maxn] , n , m , tmp , v , ans;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&tmp,&v);
        for(int j=m; j>=tmp; j--)
            if(f[j] < f[j-tmp] + v) f[j] = f[j-tmp] + v;
    }ans = f[m];while(--m) if(ans < f[m]) ans = f[m]; printf("%d",ans);
}