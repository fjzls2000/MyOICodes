/**************************************************************
    Problem: 1503
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1048 ms
    Memory:10196 kb
****************************************************************/
 
#include <stdio.h>
#define inf 233333333
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxt = 400010;
int tree[Maxt] , fa[Maxt] , lazy[Maxt] , size[Maxt] , c[Maxt][2] , root , sz = 0;
void downpush(int x) {
    int lc = c[x][0] , rc = c[x][1];
    if(lc) {
        tree[lc] += lazy[x];
        lazy[lc] += lazy[x];
    }
    if(rc) {
        tree[rc] += lazy[x];
        lazy[rc] += lazy[x];
    }lazy[x] = 0;
}
void update(int x) { size[x] = size[c[x][0]] + size[c[x][1]] + 1; }
void rotate(int&root , int x) {
    int y = fa[x] , z = fa[y] , p , q;
    if(x == c[y][0]) p = 0; else p = 1; q = p^1;
    if(y == root) root = x;
    else {
        if(y == c[z][0]) c[z][0] = x;
        else c[z][1] = x;
    }
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
    update(y); update(x);
}
void splay(int&root , int x) {
    int y , z;
    while(root != x) {
        int y = fa[x] , z = fa[y];
        if(y != root) {
            if((x == c[y][0]) ^ (y == c[z][0])) rotate(root , x);
            else rotate(root , y);
        }rotate(root , x);
    }
}
void insert(int k) {
    if(!root) { root = ++sz; fa[root] = 0; c[root][0] = c[root][1] = 0; size[root] = 1; tree[root] = k; lazy[root] = 0; return; }
    int now = root;
    while(1) {
        downpush(now); ++size[now];
        if(k <= tree[now]) {
            if(c[now][0]) now = c[now][0];
            else {
                fa[++sz] = now;
                lazy[sz] = c[sz][0] = c[sz][1] = 0;
                tree[sz] = k;
                c[now][0] = sz;
                splay(root , sz);
                return;
            }
        }
        else {
            if(c[now][1]) now = c[now][1];
            else {
                fa[++sz] = now;
                lazy[sz] = c[sz][0] = c[sz][1] = 0;
                tree[sz] = k;
                size[sz] = 1;
                c[now][1] = sz;
                splay(root , sz);
                return;
            }
        }
    }
}
int findk(int k) {
    int now = root , ans = 2;
    while(1) {
        downpush(now);
        if(k <= tree[now]) {
            ans = now;
            if(c[now][0]) now = c[now][0];
            else break;
        }
        else {
            if(c[now][1]) now = c[now][1];
            else break;
        }
    }return ans;
}
int find(int x , int k) {
    downpush(x);
    if(size[c[x][0]] + 1 == k) return tree[x];
    if(k <= size[c[x][0]]) return find(c[x][0],k);
    else return find(c[x][1] , k-size[c[x][0]]-1);
}
int main() {
    int n = F() , m = F() , cnt = 0;
    insert(-inf); insert(inf);
    while(n--) {
        char s[10]; scanf("%s",s+1); int k = F();
        if(s[1] == 'I') {
            if(k >= m) insert(k) , ++cnt;
        }
        if(s[1] == 'A') {
            tree[root] += k;
            lazy[root] += k;
        }
        if(s[1] == 'S') {
            tree[root] -= k;
            lazy[root] -= k;
            int R = findk(m);
            splay(root , R);
            int now = root;
            while(c[now][0]) downpush(now) , now = c[now][0]; downpush(now);
            splay(c[root][0] , now);
            c[now][1] = 0;
            update(now); update(root);
        }
        if(s[1] == 'F') {
            if(k > size[root]-2) puts("-1");
            else printf("%d\n",find(root , size[root]-k));
        }
    }printf("%d\n",cnt-size[root]+2 );
}