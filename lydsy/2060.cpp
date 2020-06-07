/**************************************************************
    Problem: 2060
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:32 ms
    Memory:2420 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 50001;
const int Maxm = 100001;
int f[Maxn] , g[Maxn] , to[Maxm] , next[Maxm] , h[Maxm] ; bool vis[Maxn];
const int MAXBUF = 1<<10; char B[MAXBUF] , *S = B , *T = B;
#define getc (S==T&&(T=(S=B)+fread(B,1,MAXBUF,stdin),S==T) ? EOF : *S++)
inline int F() {register int aa , ch;
    while(ch=getc , ch<'0' || ch>'9');aa=ch-'0';
    while(ch=getc , ch>='0' && ch<='9')aa=aa*10+ch-'0';return aa;
}
inline void dp(register int x) {
    f[x] = vis[x] = 1;
    for(register int i=h[x]; i; i=next[i])
        if(!vis[to[i]]) {
            dp( to[i] );
            f[x]+=g[to[i]];
            if(f[to[i]] > g[to[i]]) g[x] += f[to[i]];
            else g[x] += g[to[i]];
        }
}
 
int main() {
    register int n , i , a , b , ecnt = 0;
    i=n=F();
    while(--i) {
        a=F(); b=F();
        /*===============*/
        to[++ecnt] = b;
        next[ecnt] = h[a];
        h[a] = ecnt;
        /*===*/
        to[++ecnt] = a;
        next[ecnt] = h[b];
        h[b] = ecnt;
    }dp(1);
    if(f[1] > g[1]) printf("%d",f[1]);
    else printf("%d",g[1]);
}