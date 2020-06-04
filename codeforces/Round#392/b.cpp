#include <stdio.h>
#include <string.h>
const int Maxn = 100005;
int n , a , b , c , d , lz[5] , ans[5]; char s[Maxn];
int main() {
    scanf("%s",s+1); n = strlen(s+1);
    for(int i=1; i<=n; ++i) {
        if(s[i] == 'R') lz[i%4] = 0;
        if(s[i] == 'B') lz[i%4] = 1;
        if(s[i] == 'Y') lz[i%4] = 2;
        if(s[i] == 'G') lz[i%4] = 3;
    }
    for(int i=1; i<=n; ++i)
        if(s[i] == '!') ++ans[lz[i%4]];
    printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
}