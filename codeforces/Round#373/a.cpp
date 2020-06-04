#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int n , a[100010];
int main() {
    n = F();
    if(n == 1) {
        int qwq = F();
        if(qwq == 15) puts("DOWN");
        else if(qwq == 0) puts("UP");
        else puts("-1");
        return 0;
    }
    for(int i=1; i<=n; ++i) {
        a[i] = F();
    }
    if(a[n] < a[n-1]) {
        if(a[n] == 0) puts("UP");
        else puts("DOWN");
    }
    else {
        if(a[n] == 15) puts("DOWN");
        else puts("UP");
    }
}