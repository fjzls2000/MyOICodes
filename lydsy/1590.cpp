/**************************************************************
    Problem: 1590
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:340 ms
    Memory:8672 kb
****************************************************************/
 
#include <stdio.h>
 
#define getch() getchar()
inline int F() {
    register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 10001;
const int Maxt = 500010;
int c[Maxt][2] , sz = 1 , a[Maxn] , n , size[Maxt] , cnt[Maxt];
 
void insert() {
    int now = 1;
    for(int i=1; i<=n; ++i) {
        if(!c[now][a[i]]) c[now][a[i]] = ++sz;
        ++size[now];
        now = c[now][a[i]];
    }
    ++cnt[now];
}
int query() {
    int now = 1 , ans = 0;
    for(int i=1; i<=n; ++i) {
        if(c[now][a[i]]) {
            now = c[now][a[i]];
            ans += cnt[now];
        }
        else {
            return ans;
        }
    }
    return ans+size[now];
}
 
int main() {
    int t1 = F() , t2 = F();
    while(t1--) {
        n = F();
        for(int i=1; i<=n; ++i) {
            a[i] = F();
        }
        insert();
    }
    while(t2--) {
        n = F();
        for(int i=1; i<=n; ++i) {
            a[i] = F();
        }
        printf("%d\n",query());
    }
} 