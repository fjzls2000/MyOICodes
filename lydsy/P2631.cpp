/**************************************************************
    Problem: 2631
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:16536 ms
    Memory:4436 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int mod = 51061;
const int Maxn = 100005;
int n , q , size[Maxn] , fa[Maxn] , c[Maxn][2] , st[Maxn] , top;
unsigned int sum[Maxn] , val[Maxn] , lazy[Maxn] , mul[Maxn];
bool rev[Maxn];
bool isroot(int x) { return (c[fa[x]][0] != x && c[fa[x]][1] != x); }
void cal(int x , int l , int m) {
    if(!x) return;
    sum[x] = (sum[x]*m + l*size[x]) % mod;
    val[x] = (val[x]*m + l) % mod;
    lazy[x] = (lazy[x]*m + l) % mod;
    mul[x] = (mul[x]*m) % mod;
}
void update(int x) {
    int lc = c[x][0] , rc = c[x][1];
    size[x] = (size[lc] + size[rc] + 1)%mod;
    sum[x] = (sum[lc] + sum[rc] + val[x])%mod;
}
void downpush(int x) {
    int lc = c[x][0] , rc = c[x][1];
    if(rev[x]) {
        if(lc) rev[lc]^=1;
        if(rc) rev[rc]^=1;
        c[x][0] = rc; c[x][1] = lc;
        rev[x] = 0;
    }
    int t1 = lazy[x] , t2 = mul[x];
    lazy[x] = 0; mul[x] = 1;
    if(t1!=0||t2!=1) {
        cal(lc,t1,t2);
        cal(rc,t1,t2);
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
    for(int i=x; !isroot(i); i = fa[i]) st[++top] = fa[i];
    while(top) downpush(st[top--]);
    while(!isroot(x)) {
        int y = fa[x] , z = fa[y];
        if(!isroot(y)) {
            if((x == c[y][0]) ^ (y == c[z][0])) rotate(x);
            else rotate(y);
        } rotate(x);
    }
}
void access(int x) { for(int t=0; x; t = x , x = fa[x]) { splay(x); c[x][1] = t; update(x); } }
void makeroot(int x) { access(x); splay(x); rev[x] ^= 1; }
void split(int x , int y) { makeroot(y); access(x); splay(x); }
void link(int x , int y) { makeroot(x); fa[x] = y; }
void cut(int x , int y) { makeroot(x); access(y); splay(y); fa[x] = c[y][0] = 0; }
char op[20];
int main() {
    n = F() , q = F();
    for(int i=1; i<=n; ++i) size[i] = sum[i] = val[i] = mul[i] = 1;
    for(int i=1; i<n; ++i) {
        int a = F() , b = F();
        link(a,b);
    }
    while(q--) {
        scanf("%s",op);
        int x = F() , y = F();
        if(op[0] == '+') {
            int val = F();
            split(x,y); cal(x,val,1);
        }
        if(op[0] == '-') {
            cut(x,y);
            x = F() , y = F();
            link(x,y);
        }
        if(op[0] == '*') {
            int val = F();
            split(x,y); cal(x,0,val);
        }
        if(op[0] == '/') {
            split(x,y);
            printf("%u\n",sum[x]);
        }
    }
}