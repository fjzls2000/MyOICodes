/**************************************************************
    Problem: 1688
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:108 ms
    Memory:952 kb
****************************************************************/
 
#include <stdio.h>
 
inline int max(int a , int b) { return a > b ? a : b ; }
 
int n , d , k , ed , ans;
int bin[20] , a[1005] , f[1<<15];
 
#define getch() getchar()
inline int F() {register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
bool jud(int x) {
    int tot = 0;
    for(int i=1; i<=d; ++i)
        if(bin[i-1]&x) {
            ++tot;
            if(tot > k) return 0;
        }
    return 1;
}
 
int main() {
    bin[0] = 1; for(int i=1; i<=15; ++i) bin[i] = bin[i-1]<<1;
    n = F(); d = F() ; k = F();
    ed = (1<<d)-1;
    for(int i=1; i<=n; ++i) {
        int x = F() , y;
        while(x--)
            y = F() , a[i]+=bin[y-1];
    }
    for(int i=1; i<=n; ++i)
        for(int j=ed; j>=0; --j)
            f[j|a[i]] = max(f[j|a[i]],f[j]+1);
    for(int i=0; i<=ed; ++i)
        if(jud(i)) ans = max(ans , f[i]);
    printf("%d\n",ans);
}