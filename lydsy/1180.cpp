/**************************************************************
    Problem: 1180
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:5008 ms
    Memory:3264 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
int n , q , top;
int c[Maxn][2] , fa[Maxn] , s[Maxn] , v[Maxn] , st[Maxn];
bool rev[Maxn];
void update(int x) {
    int lc = c[x][0] , rc = c[x][1];
    s[x] = s[lc] + s[rc] + v[x];
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
bool isroot(int x) { return (c[fa[x]][0] != x && c[fa[x]][1] != x); }
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
    top = 0; st[++top] = x;
    for(int i=x; !isroot(i); i=fa[i]) st[++top] = fa[i];
    while(top) downpush(st[top--]);
    while(!isroot(x)) {
        int y = fa[x] , z = fa[y];
        if(!isroot(y)) {
            if((x == c[y][0]) ^ (y == c[z][0])) rotate(x);
            else rotate(y);
        }rotate(x);
    }
}
void access(int x) {
    for(int t=0; x; t=x,x=fa[x])
        splay(x) , c[x][1] = t , update(x);
}
void makeroot(int x) {
    access(x); splay(x); rev[x] ^= 1;
}
void link(int x , int y) {
    makeroot(x); fa[x] = y;
}
int getrt(int x) {
    access(x); splay(x);
    while(c[x][0]) x = c[x][0];
    return x;
}
char op[20];
int main() {
    n = F();
    for(int i=1; i<=n; ++i) s[i] = v[i] = F();
    q = F();
    while(q--) {
        scanf("%s",op);
        int x = F() , y = F();
        if(op[0] == 'b') {
            if(getrt(x) == getrt(y)) puts("no");
            else puts("yes"),link(x,y);
        }
        if(op[0] == 'p') {
            makeroot(x); v[x]=y; update(x);
        }
        if(op[0] == 'e') {
            if(getrt(x) != getrt(y)) puts("impossible");
            else {
                makeroot(x) , access(y) , splay(y);
                printf("%d\n",s[y]);
            }
        }
    }
}