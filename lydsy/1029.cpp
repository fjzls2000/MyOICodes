/**************************************************************
    Problem: 1029
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:304 ms
    Memory:2384 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <queue>
const int Maxn = 150010;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
std::priority_queue<int> q;
struct node { int r , t; } a[Maxn];
inline bool cmp(node a , node b) { return a.r < b.r; }
int n;
int main() {
    n = F();
    for(int i=1; i<=n; ++i)
        a[i].t = F() , a[i].r = F();
    std::sort(a+1,a+n+1,cmp);
    int now = 0 , ans = 0;
    for(int i=1; i<=n; ++i) {
        if(now + a[i].t < a[i].r) {
            ++ans; now += a[i].t;
            q.push(a[i].t);
        }
        else {
            if(q.top() < a[i].t) continue;
            now -= q.top(); q.pop();
            now += a[i].t; q.push(a[i].t);
        }
    }printf("%d\n",ans );
}