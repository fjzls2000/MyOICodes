/**************************************************************
    Problem: 1604
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1244 ms
    Memory:6200 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <set>
#define ll long long
inline int max(int x , int y) { return x > y ? x : y ; }
#define inf 10000000000LL
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
struct node { ll x , y , id; } a[Maxn];
bool cmpx(node a , node b) { return a.x < b.x; }
bool operator < (node a , node b) { return a.y < b.y; }
std::multiset <node> b;
std::set <node>::iterator it;
int n , c , fa[Maxn] , tot[Maxn] , ans , mx = 0;
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void un (int x , int y) {
    int p = find(x) , q = find(y);
    if(p != q) {
        fa[p] = q;
        --ans;
    }
}
void Solve() {
    b.insert((node){0,inf,0});b.insert((node){0,-inf,0});
    int now = 1;b.insert(a[1]);
    for(int i=2; i<=n; ++i) {
        while(a[i].x - a[now].x > c) {
            b.erase(b.find(a[now]));
            now++;
        }
        it = b.lower_bound(a[i]);
        node r = *it , l = *--it;
        if(a[i].y-l.y <= c)
            un(a[i].id,l.id);
        if(r.y-a[i].y <= c)
            un(a[i].id,r.id);
        b.insert(a[i]);
    }
}
int main() {
    n = F(); c = F(); ans = n;
    for(int i=1; i<=n; ++i) {
        fa[i] = i;
        int t1 = F() , t2 = F();
        a[i].x = t1+t2 , a[i].y = t1-t2; a[i].id = i;
    }
    std::sort(a+1,a+n+1,cmpx);
    Solve();
    for(int i=1; i<=n; ++i)
        ++tot[find(i)];
    for(int i=1; i<=n; ++i)
        mx = max(mx , tot[i]);
    printf("%d %d",ans,mx);
}