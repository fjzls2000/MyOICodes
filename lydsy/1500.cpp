/**************************************************************
    Problem: 1500
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:4888 ms
    Memory:46560 kb
****************************************************************/
 
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#define inf 1000000000
using namespace std;
#define getch() getchar()
inline int F() {register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 1000005;
queue<int> q;
int n , m , root , sz;
int fa[Maxn] , c[Maxn][2] , mx[Maxn] , lx[Maxn] , rx[Maxn] , v[Maxn] , size[Maxn] , sum[Maxn] , a[Maxn] , id[Maxn];
bool lazy[Maxn] , rev[Maxn];
 
void update(int x) {
    int lc = c[x][0] , rc = c[x][1];
    sum[x] = sum[lc] + sum[rc] + v[x];
    size[x] = size[lc] + size[rc] + 1;
    mx[x] = max(mx[lc] , mx[rc]);
    mx[x] = max(mx[x] , rx[lc]+v[x]+lx[rc]);
    lx[x] = max(lx[lc] , sum[lc] + v[x] + lx[rc]);
    rx[x] = max(rx[rc] , sum[rc] + v[x] + rx[lc]);
}
 
void downpush(int x) {
    int lc = c[x][0] , rc = c[x][1];
    if(lazy[x]) {
        rev[x] = lazy[x] = 0;
        if(lc) lazy[lc] = 1 , v[lc] = v[x] , sum[lc] = v[x]*size[lc];
        if(rc) lazy[rc] = 1 , v[rc] = v[x] , sum[rc] = v[x]*size[rc];
        if(v[x] >= 0) {
            if(lc) lx[lc] = rx[lc] = mx[lc] = sum[lc];
            if(rc) lx[rc] = rx[rc] = mx[rc] = sum[rc];
        }
        else {
            if(lc) lx[lc] = rx[lc] = 0 , mx[lc] = v[x];
            if(rc) lx[rc] = rx[rc] = 0 , mx[rc] = v[x];
        }
    }
    if(rev[x]) {
        rev[x] = 0;
        rev[lc] ^= 1;
        rev[rc] ^= 1;
        swap(lx[lc] , rx[lc]);
        swap(lx[rc] , rx[rc]);
        c[x][0] = rc;
        c[x][1] = lc;
        swap(lx[x] , rx[x]);
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
    int lc = c[x][0] , rc = c[x][1];
    if(size[lc] + 1 == rk) return x;
    if(size[lc] >= rk) return find(lc , rk);
    else return find(rc , rk-size[lc]-1);
}
 
void rec(int x) {
    if(!x) return ;
    int lc = c[x][0] , rc = c[x][1];
    rec(lc);rec(rc);q.push(x);
    fa[x] = c[x][0] = c[x][1] = lazy[x] = rev[x] = 0;
}
 
int split(int k , int tot) {
    int x = find(root , k);
    splay(root , x);
    x = find(root , k+tot+1);
    splay(c[root][1] , x);
    return c[ c[root][1] ][0];
}
 
void query(int k , int tot) {
    int x = split(k , tot);
    printf("%d\n",sum[x]);
}
 
void modify(int k , int tot , int val) {
    int x = split(k , tot) , y = fa[x];
    v[x] = val; lazy[x] = 1; sum[x] = size[x]*val;
    if(val >= 0) lx[x] = rx[x] = mx[x] = sum[x];
    else lx[x] = rx[x] = 0 , mx[x] = val;
    update(y); update(fa[y]);
}
 
void reverse(int k , int tot) {
    int x = split(k , tot);
    if(!lazy[x]) {
        rev[x] ^= 1;
        downpush(x);
        update(fa[x]);
        update(fa[fa[x]]);
    }
}
 
void erase(int k , int tot) {
    int x = split(k , tot) , y = fa[x];
    rec(x); c[y][0] = 0;
    update(y); update(fa[y]);
}
/*
void Build(int l , int r , int&x , int f) {
    if(l > r) return ;
    if(!q.empty()) {
        x = q.front();
        q.pop();
    }
    else x = ++sz;
    int mid = (l + r) >> 1;
    fa[x] = f;
    v[x] = a[mid];
    if(l == r) {
        sum[x] = v[x];
        size[x] = 1;
        if(v[x] >= 0) lx[x] = rx[x] = mx[x] = v[x];
        else lx[x] = rx[x] = 0 , mx[x] = v[x]; 
    }
    else {
        Build(l , mid-1 , c[x][0] , x);
        Build(mid+1 , r , c[x][1] , x);
        update(x);
    }
}
void insert(int k , int tot) {
    for(int i=1; i<=tot; ++i) {
        a[i] = F();
    }
    split(k , 0);
    int x = c[root][1];
    Build(1,tot,c[x][0],x);
}*/
void build(int l,int r,int f)
{
    if(l>r)return;
    int mid=(l+r)>>1,now=id[mid],last=id[f];
    if(l==r)
    {
        sum[now]=a[l];size[now]=1;
        lazy[now]=rev[now]=0;
        if(a[l]>=0)lx[now]=rx[now]=mx[now]=a[l];
        else lx[now]=rx[now]=0,mx[now]=a[l];
    }
    else build(l,mid-1,mid),build(mid+1,r,mid);
    v[now]=a[mid];fa[now]=last;update(now);
    c[last][mid>=f]=now;
   }
void insert(int k,int tot)
{
    for(int i=1;i<=tot;i++)a[i]=F();
    for(int i=1;i<=tot;i++)
        if(!q.empty())id[i]=q.front(),q.pop();
        else id[i]=++sz;
    build(1,tot,0);int z=id[(1+tot)>>1];
    int x=find(root,k+1),y=find(root,k+2);
    splay(root,x);splay(c[x][1],y);
    fa[z]=y;c[y][0]=z;
    update(y);update(x);
}
 
int main() {
    n = F(); m = F();
    mx[0] = a[1] = a[n+2] = -inf;
    for(int i=1; i<=n; ++i) {
        a[i+1] = F();
    }
    for(int i=1;i<=n+2;i++)id[i]=i;
    build(1,n+2,0);
    root = (n+3) >> 1;sz = n + 2;
    int k , tot , val;
    char ch[10];
    while(m--) {
        scanf("%s",ch);
        if(ch[0]!='M' || ch[2] != 'X') k = F() , tot = F();
        if(ch[0] == 'I') insert(k , tot);
        if(ch[0] == 'D') erase(k , tot);
        if(ch[0] == 'M') {
            if(ch[2] == 'X') printf("%d\n",mx[root]);
            else val = F() , modify(k , tot , val);
        }
        if(ch[0] == 'R') reverse(k , tot);
        if(ch[0] == 'G') query(k , tot);
    }
}