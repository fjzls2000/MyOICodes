#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 500005;
int n , m , p , ch , a[Maxn] , fal[Maxn] , far[Maxn];
int findl(int x) { return fal[x] == x ? x : fal[x] = findl(fal[x]); }
int findr(int x) { return far[x] == x ? x : far[x] = findr(far[x]); }
int main() {
    n = F() , m = F() , p = F();
    for(int i=1; i<=n; ++i) {
        fal[i] = far[i] = i;
        while(ch = getchar() , ch!='(' && ch!=')');
        if(ch == '(') a[i] = -1;
        else a[i] = 1;
    }
    far[n+1] = fal[n+1] = n+1;
    far[n+2] = fal[n+2] = n+2;
    while(m--) {
        while(ch = getchar() , ch!='L' && ch!='R' && ch!='D');
        if(ch == 'L') { p = findl(p-1); }
        if(ch == 'R') { p = findr(p+1); }
        if(ch == 'D') {
            if(a[p] == 1) {
                int now = 0;
                while(1) {
                    now += a[p];
                    fal[p] = p-1;
                    far[p] = p+1;
                    if(now == 0) {
                        if(findr(p) <= n) p = findr(p);
                        else if(findl(p) >= 1) p = findl(p);
                        else return 0;
                        break;
                    }p = findl(p);
                }
            }
            else {
                int now = 0;
                while(1) {
                    now += a[p];
                    fal[p] = p-1;
                    far[p] = p+1;
                    if(now == 0) {
                        if(findr(p) <= n) p = findr(p);
                        else if(findl(p) >= 1) p = findl(p);
                        else return 0;
                        break;
                    }p = findr(p);
                }
            }
        }
    }
    int now = 1;
    while(now <= n) {
        int x = findr(now);
        if(x <= n) {
            if(a[x] == -1) putchar('(');
            else putchar(')');
        }
        now = x+1;
    }
}