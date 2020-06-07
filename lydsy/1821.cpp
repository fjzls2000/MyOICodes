/**************************************************************
    Problem: 1821
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:400 ms
    Memory:16472 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <math.h>
inline int F() {register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 1010;
const int Maxm = 1000001;
struct E { int a , b ;double w; } e[Maxm];
bool cmp(E a , E b) { return a.w < b.w; }
double x[Maxn] , y[Maxn];
int n , k , fa[Maxn] , cnt = 0;
void ins(int a , int b) {
    e[++cnt].a = a;
    e[cnt].b = b;
    e[cnt].w = sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
int main() {
    n = F(); k = F();
    for(int i=1; i<=n; ++i)
        x[i] = F() , y[i] = F() , fa[i] = i;
    for(int i=1; i<=n; ++i)
        for(int j=i+1; j<=n; ++j)
            ins(i,j);
    std::sort(e+1,e+cnt+1,cmp);
    for(int i=1; i<=cnt; ++i) {
        if(find(e[i].a) != find(e[i].b)) {
            if(n > k) {
                --n;
                fa[fa[e[i].a]] = fa[e[i].b];
            }
            else {
                printf("%.2lf",e[i].w);
                break;
            }
        }
    }
}