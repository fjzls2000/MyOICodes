/**************************************************************
    Problem: 1614
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:36 ms
    Memory:5680 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#define inf 2147483647
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
using namespace std;
const int Maxn = 2010;
const int Maxm = 40010;
int n , m , k , to[Maxm] , next[Maxm] , g[Maxn] , w[Maxm] , ecnt = 0 , q[1000010] , dis[Maxn];
bool inq[Maxn];
void ins(int a , int b , int wi) {
    to[++ecnt] = b;
    next[ecnt] = g[a];
    g[a] = ecnt;
    w[ecnt] = wi;
}
bool check(int lim) {
    memset(dis,42,sizeof(dis));
    int h , t;
    dis[1] = 0;
    q[h = t = 1] = 1;
    inq[1] = 1;
    while(h <= t) {
        int now = q[h++];
        for(int i=g[now]; i; i=next[i]) {
            int dist = dis[now] + (w[i] > lim);
            if(dist < dis[to[i]]) {
                dis[to[i]] = dist;
                if(!inq[to[i]]) {
                    inq[to[i]] = 1;
                    q[++t] = to[i];
                }
            }
        }
        inq[now] = 0;
    }
    if(dis[n] <= k)
        return 1;
    else
        return 0;
}
 
int main() {
    n = F(); m = F(); k = F();
    for(int i=1; i<=m; ++i) {
        int a = F() , b = F() , wi = F();
        ins(a , b , wi);
        ins(b , a , wi);
    }
    int l = 0 , r = 1000000 , mid , ans = -1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
}