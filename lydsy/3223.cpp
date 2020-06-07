/**************************************************************
    Problem: 3223
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:2604 ms
    Memory:3264 kb
****************************************************************/
 
#include <stdio.h>
#define inf 233333333
 
const int Maxn = 100010;
int n , root , size[Maxn] , c[Maxn][2] , fa[Maxn] , a[Maxn] , tree[Maxn];
bool rev[Maxn];
 
void update(int x) {
    size[x] = size[c[x][0]] + size[c[x][1]] + 1;
}
 
void downpush(int x) {
    if(rev[x]) {
        int lc = c[x][0] , rc = c[x][1];
        if(lc) rev[lc] ^= 1;
        if(rc) rev[rc] ^= 1;
        c[x][0] = rc;
        c[x][1] = lc;
        rev[x] = 0;
    }
}
 
void rotate(int&root , int x) {
    int y = fa[x] , z = fa[y] , p , q;
    if(x == c[y][0]) p = 0; else p = 1;
    q = p^1;
    if(y == root) root = x;
    else {
        if(c[z][0] == y) c[z][0] = x;
        else c[z][1] = x;
    }
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
    update(y); update(x);
}
void splay(int&root , int x) {
    int y , z;
    while(x != root) {
        y = fa[x] , z = fa[y];
        if(y != root) {
            if((x == c[y][0]) ^ (y == c[z][0])) rotate(root , x);
            else rotate(root , y);
        }
        rotate(root , x);
    }
}
 
int find(int x , int rk) {
    downpush(x);
    int y = c[x][0];
    if(size[y] + 1 == rk) return x;
    if(size[y] >= rk) return find(y , rk);
    else return find(c[x][1] , rk-size[y]-1);
}
 
int split(int k , int tot) {
    int x = find(root , k);
    splay(root , x);
    x = find(root , tot+2);
    splay(c[root][1] , x);
    return c[ c[root][1] ][0];
}
 
int reverse(int l , int r) {
    int x = split(l , r);
    rev[x] ^= 1;
}
 
void Build(int l , int r , int lst) {
    if(l > r) return;
    int mid = (l + r) >> 1;
    fa[mid] = lst;
    if(mid < lst)
        c[lst][0] = mid;
    else
        c[lst][1] = mid;
    tree[mid] = a[mid];
    size[mid] = 1;
    if(l == r)
        return;
    Build(l,mid-1,mid);
    Build(mid+1,r,mid);
    update(mid);
}
 
int main() {
    int m;
    scanf("%d%d",&n,&m);
    for(int i=2; i<=n+1; ++i) {
        a[i] = i-1;
    }
    a[1] = a[n+2] = -inf;
    Build(1,n+2,0);
    root = (n+3) >> 1;
    while(m--) {
        int ta , tb;
        scanf("%d%d",&ta,&tb);
        reverse(ta,tb);
    }
    for(int i=1; i<=n; ++i) {
        printf("%d ",tree[find(root,i+1)]);
    }
}