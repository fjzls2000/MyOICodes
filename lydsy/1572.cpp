/**************************************************************
    Problem: 1572
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:260 ms
    Memory:2380 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <queue>
#define getch() getchar()
int F() {register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10+ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
struct node { int t , k; } a[Maxn];
bool cmp(node a , node b) { return a.t < b.t; }
std::priority_queue<int> q;
int main() {
    long long ans = 0 , tot = 0;
    int sz = 0 , n = F();
    for(int i=1; i<=n; ++i) a[i].t = F() , tot += (a[i].k = F());
    std::sort(a+1,a+n+1,cmp);
    for(int i=1; i<=n; ++i) {
        if(sz >= a[i].t) {
            q.push(-a[i].k);
            ans+=q.top();
            q.pop();
        }
        else ++sz , q.push(-a[i].k);
    }printf("%lld",tot + ans);
}