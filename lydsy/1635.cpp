/**************************************************************
    Problem: 1635
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1992 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
using namespace std;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
struct node { int l , r; } d[Maxn];
bool cmp(node a , node b) { return a.l == b.l ? a.r > b.r : a.l > b.l ; }
int n , m , h , a[Maxn];
int main() {
    n = F() , F() , h = F() , m = F();
    for(int i=1; i<=m; ++i) {
        int l = F() , r = F();
        if(l > r) swap(l , r);
        d[i].l = l , d[i].r = r;
    }
    std::sort(d+1,d+m+1,cmp);
    for(int i=1; i<=m; ++i) {
        if(d[i].l == d[i-1].l && d[i].r == d[i-1].r) continue;
        int l = d[i].l , r = d[i].r;
        ++a[l+1]; --a[r];
    }
    int sum = 0;
    for(int i=1; i<=n; ++i) {
        sum += a[i];
        printf("%d\n",h-sum);
    }
}