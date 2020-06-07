/**************************************************************
    Problem: 1026
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:824 kb
****************************************************************/
 
#include <stdio.h>
inline int abs(int a) { return a >= 0 ? a : -a ; }
inline int F() {
    register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int l , r , E[15] , f[15][15];
void init() {
    l = F() , r = F();
    E[1] = 1; for(int i=2; i<=10; ++i) E[i] = E[i-1]*10;
    for(int i=0; i<10; ++i) f[1][i] = 1;
    for(int i=2; i<=10; ++i) for(int j=0; j<10; ++j) for(int k=0; k<10; ++k)
        if(abs(j-k) >= 2) f[i][j] += f[i-1][k];
}
int calc(int x) {
    if(!x) return 0;
    int tmp = 0 , w = 10;
    while(E[w] > x) --w;
    for(int i=1; i<w; ++i)
        for(int j=1; j<=9; ++j)
            tmp+=f[i][j];
    int cur = x/E[w];
    for(int i=1; i<cur; ++i) tmp += f[w][i];
    x %= E[w];
    int pre = cur;
    for(int i=w-1; i; --i) {
        cur = x/E[i];
        if(i!=1) {
            for(int j=0; j<cur; ++j)
                if(abs(pre-j) >= 2) tmp += f[i][j];
        }
        else {
            for(int j=0; j<=cur; ++j)
                if(abs(pre-j) >= 2) tmp += f[i][j];
        }
        if(abs(cur-pre) < 2) break;
        pre = cur;
        x%=E[i];
    }
    return tmp;
}
int main() {
    init();
    printf("%d",calc(r)-calc(l-1));
}