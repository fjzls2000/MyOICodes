/**************************************************************
    Problem: 1594
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:460 ms
    Memory:28168 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
inline int max(int a , int b) { return a > b ? a : b ; }
inline int min(int a , int b) { return a < b ? a : b ; }
const int Maxn = 1000010;
 
int n , tt , mid , fa[Maxn];
struct Q { int l , r , x; } q[Maxn] , tmp[Maxn];
bool cmp(Q a , Q b) { return a.x > b.x;}
 
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}
 
bool check() {
    for(int i=1; i<=mid; ++i) tmp[i] = q[i];
    std::sort(tmp+1,tmp+mid+1,cmp);
    for(int i=1; i<=n; ++i) fa[i] = i;
    for(int i=1; i<=mid; ++i) {
        int la,ra,lb,rb;
        la=lb=tmp[i].l;
        ra=rb=tmp[i].r;
        while(i<mid && tmp[i+1].x == tmp[i].x) {
            ++i;
            la=min(la,tmp[i].l);
            ra=max(ra,tmp[i].r);
            lb=max(lb,tmp[i].l);
            rb=min(rb,tmp[i].r);
        }
        if(find(rb)+1 <= lb) return true;
        for(int t=ra,p=find(t); p>=la; t=p-1,p=find(t))
            fa[p]=la-1;
    }
    return false;
}
 
int main() {
    scanf("%d%d",&n,&tt);
    for(int i=1; i<=tt; ++i)
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].x);
    int l = 1 , r = tt , ans = -1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check()) ans = mid , r = mid - 1;
        else l = mid + 1;
    }
    if(ans == -1)puts("0");
    else printf("%d",ans);
}