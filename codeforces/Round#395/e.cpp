#include <stdio.h>
#include <vector>
#include <iostream>
#define inf 233333333
using namespace std;
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
const int Maxm = 600005;
struct E { int a , b; } e[Maxm];
int n , m , k , q , id , val[Maxm] , ans[Maxn];
std::vector<int> vec[Maxn];
std::vector< pair<int,int> > que[Maxn];
int fa[Maxm] , c[Maxm][2] , mx[Maxm] , mn[Maxm] , st[Maxm] , top;
bool rev[Maxm];
bool isroot(int x) { return (c[fa[x]][0] != x && c[fa[x]][1] != x); }
void update(int x) {
    int lc = c[x][0] , rc = c[x][1];
    mx[x] = x;
    if(lc && val[mx[lc]] > val[mx[x]]) mx[x] = mx[lc];
    if(rc && val[mx[rc]] > val[mx[x]]) mx[x] = mx[rc];
}
void downpush(int x) {
    int lc = c[x][0] , rc = c[x][1];
    if(rev[x]) {
        if(lc) rev[lc] ^= 1;
        if(rc) rev[rc] ^= 1;
        c[x][0] = rc; c[x][1] = lc;
        rev[x] = 0;
    }
}
void rotate(int x) {
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
void access(int x) { for(int t=0; x; t=x,x=fa[x]) { splay(x); c[x][1] = t; update(x); } }
void makeroot(int x) { access(x); splay(x); rev[x] ^= 1; }
void link(int x , int y) { makeroot(x); fa[x] = y; }
void cut(int x , int y) { makeroot(x); access(y); splay(y); c[y][0] = fa[x] = 0; }
int findroot(int x) {
    access(x); splay(x);
    while(c[x][0]) x = c[x][0];
    return x;
}
int BIT[Maxn];
#define lowbit(x) ((x) & -(x))
void add(int x , int val) { for(; x <= n; x += lowbit(x)) BIT[x] += val; }
int query(int x) {
    int val = 0;
    for(; x; x-=lowbit(x)) val += BIT[x];
    return val;
}
int main() {
    n = F() , k = F() , m = F();
    for(int i=1; i<=n; ++i) { val[i] = -inf; mx[i] = i; }
    id = n;
    for(int i=1; i<=m; ++i) {
        e[i].a = F() , e[i].b = F();
        if(e[i].a > e[i].b) swap(e[i].a,e[i].b);
        val[++id] = e[i].b; mx[id] = id;
        vec[e[i].a].push_back(i);
    }
    int q = F();
    for(int i=1; i<=q; ++i) {
        int a = F() , b = F();
        que[a].push_back(make_pair(b,i));
    }
    for(int i=n; i; --i) {
        for(int j=0; j<vec[i].size(); ++j) {
            int now = vec[i][j];
            if(findroot(e[now].a) != findroot(e[now].b)) {
                link(e[now].a,n+now); link(e[now].b,n+now);
                add(val[n+now],1);
            }
            else {
                makeroot(e[now].a); access(e[now].b); splay(e[now].b);
                int x = mx[e[now].b];
                if(val[x] > val[n+now]) {
                    cut(e[x-n].a,x); cut(e[x-n].b,x); add(val[x],-1);
                    link(e[now].a,n+now); link(e[now].b,n+now); add(val[n+now],1);
                }
            }
        }
        for(int j=0; j<que[i].size(); ++j) {
            int qr = que[i][j].first , qi = que[i][j].second;
            ans[qi] = (qr - i + 1) - query(qr);
        }
    }
    for(int i=1; i<=q; ++i) printf("%d\n",ans[i]);
}