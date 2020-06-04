#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int main() {
    int n = F(); puts("YES");
    for(int i=1; i<=n; ++i) {
        int a = F() , b = F() , c = F() , d = F();
        a = (a%2+2)%2; b = (b%2+2)%2;
        printf("%d\n",1+a+a+b);
    }
}