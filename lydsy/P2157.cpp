/**************************************************************
    Problem: 2157
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:808 ms
    Memory:4532 kb
****************************************************************/
 
#include <stdio.h>
#define inf 233333333
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
int n , q , ed[Maxn] , id , fa[Maxn] , c[Maxn][2] , st[Maxn] , top = 0;
int val[Maxn] , sum[Maxn] , mx[Maxn] , mn[Maxn];
bool rev[Maxn] , lazy[Maxn];
bool isroot(int x) { return (c[fa[x]][0] != x && c[fa[x]][1] != x); }
void rever(int x) {
    val[x] = -val[x];
    sum[x] = -sum[x];
    int a = mn[x] , b = mx[x];
    mx[x] = -a; mn[x] = -b;
    lazy[x] ^= 1;
}
void update(int x) {
    int lc = c[x][0] , rc = c[x][1];
    mn[x] = min(mn[lc] , mn[rc]);
    mx[x] = max(mx[lc] , mx[rc]);
    if(x > n) mn[x] = min(mn[x] , val[x]);
    if(x > n) mx[x] = max(mx[x] , val[x]);
    sum[x] = sum[lc] + sum[rc] + val[x];
}
void downpush(int x) {
    int lc = c[x][0] , rc = c[x][1];
    if(lazy[x]) {
        lazy[x] = 0;
        if(lc) rever(lc);
        if(rc) rever(rc);
    }
    if(rev[x]) {
        if(lc) rev[lc] ^= 1;
        if(rc) rev[rc] ^= 1;
        c[x][0] = rc; c[x][1] = lc;
        rev[x] = 0;
    }
}
void rotate(int&x) {
    int y = fa[x] , z = fa[y] , p,q;
    if(x == c[y][0]) p = 0; else p = 1; q = p^1;
    if(!isroot(y)) {
        if(y == c[z][0]) c[z][0] = x;
        else c[z][1] = x;
    }
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
    update(y); update(x);
}
void splay(int x) {
    st[++top] = x;
    for(int i=x; !isroot(i); i=fa[i]) st[++top] = fa[i];
    while(top) downpush(st[top--]);
    while(!isroot(x)) {
        int y = fa[x] , z = fa[y];
        if(!isroot(y)) {
            if((x == c[y][0]) ^ (y == c[z][0])) rotate(x);
            else rotate(y);
        } rotate(x);
    }
}
void access(int x) {
    for(int t=0; x; t = x , x = fa[x]) {
        splay(x); c[x][1] = t; update(x);
    }
}
void makeroot(int x) { access(x); splay(x); rev[x] ^= 1; }
void link(int x , int y) { makeroot(x); fa[x] = y; }
void split(int x , int y) { makeroot(y); access(x); splay(x); }
char op[20];
int main() {
    n = F();
    for(int i=0; i<=n; ++i) mx[i] = -inf , mn[i] = inf;
    id = n;
    for(int i=1; i<n; ++i) {
        int a = F()+1 , b = F()+1 , wi = F();
        ed[i] = ++id;
        link(a,id); link(id,b);
        val[id] = sum[id] = mx[id] = mn[id] = wi;
    }
    q = F();
    while(q--) {
        scanf("%s",op);
        int x = F() , y = F();
        if(op[0] == 'C') { makeroot(ed[x]); val[ed[x]] = y; update(ed[x]); }
        if(op[0] == 'N') { split(x+1,y+1); rever(x+1); }
        if(op[0] == 'S') { split(x+1,y+1); printf("%d\n",sum[x+1]); }
        if(op[0] == 'M') {
            if(op[1] == 'A') { split(x+1,y+1); printf("%d\n",mx[x+1]); }
            else { split(x+1,y+1); printf("%d\n",mn[x+1]); }
        }
    }
}