#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch!='-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int gcd(int a , int b) { return b ? gcd(b,a%b) : a; }
int main() {
    int n = F() , m = F() , k = F();
    int lcm = n*m/gcd(n,m);
    printf("%d\n",k/lcm);
}