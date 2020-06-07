/**************************************************************
    Problem: 1651
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:964 ms
    Memory:63328 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 1000100;
inline int max(register int a , register int b) { return a > b ? a : b ; }
inline int min(register int a , register int b) { return a < b ? a : b ; }
 
int ll[4*Maxn] , rr[4*Maxn] , tree[4*Maxn] , lazy[4*Maxn] , n , a , b;
 
void Build(int x , int l , int r) {
    ll[x] = l ; rr[x] = r ;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    Build(x<<1 , l , mid) ; Build(x<<1|1 , mid+1 , r);
}
 
void downpush(int x) {
    int lc = x<<1 , rc = x<<1|1;
    if(lazy[x]) {
        tree[x] += lazy[x];
        if(ll[x] != rr[x]) lazy[lc] += lazy[x] , lazy[rc] += lazy[x] ;
        lazy[x] = 0;
    }
}
 
void update(int x , int l , int r) {
    downpush(x);
    l = max(l , ll[x]); r = min(r , rr[x]);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) ++lazy[x];
    else update(x<<1 , l , r) , update(x<<1|1 , l , r) ,tree[x] = max(tree[x<<1] , tree[x<<1|1]);
    downpush(x);
}
 
int main() {
    scanf("%d",&n);
    Build(1,1,1000000);
    while(n--) {
        scanf("%d%d",&a,&b);
        update(1,a,b);
    } 
    downpush(1);
    printf("%d",tree[1]);
}