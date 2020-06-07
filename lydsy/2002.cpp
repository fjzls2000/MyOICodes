/**************************************************************
    Problem: 2002
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1424 ms
    Memory:4440 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define getch() getchar()
inline int F() {
    register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200010;
const int Maxbl = 2001;
int n , m , pt[Maxn] , st[Maxn] , block , cnt , belong[Maxn] , l[Maxbl] , r[Maxbl] , k[Maxn];
int cal(int x) {
    int tmp = 0;
    while(1) {
        if(pt[x]) {
            tmp += st[x];
            x = pt[x];
        }
        else
            return tmp + st[x];
    }
}
int main() {
    n = F();
    block = sqrt(n);
    for(int i=1; i<=n; ++i) {
        k[i] = F();
    }
    if(n%block) cnt = n/block+1;
    else cnt = n/block;
    for(int i=1; i<=cnt; ++i)
        l[i] = (i-1)*block+1 , r[i] = i*block;
    r[cnt] = n;
    for(int i=1; i<=n; ++i)
        belong[i] = (i-1)/block+1;
    for(int i=n; i; --i) {
        if(i+k[i]>n) st[i] = 1;
        else
            if(belong[i] == belong[i+k[i]]) {
                st[i] = st[i+k[i]]+1;
                pt[i] = pt[i+k[i]];
            }
            else {
                st[i] = 1;
                pt[i] = i+k[i];
            }
    }
    m = F();
    for(int i=1; i<=m; ++i) {
        int f = F() , x = F() , y;
        ++x;
        if(f == 1) printf("%d\n",cal(x));
        else {
            y = F();k[x] = y;
            for(int i=x; i>=l[belong[x]]; --i)
                if(belong[i] == belong[i+k[i]]) {
                    st[i] = st[i+k[i]] + 1;
                    pt[i] = pt[i+k[i]];
                }
                else {
                    st[i] = 1;
                    pt[i] = i+k[i];
                }
        }
    }
}