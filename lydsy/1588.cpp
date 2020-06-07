/**************************************************************
    Problem: 1588
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:160 ms
    Memory:2384 kb
****************************************************************/
 
#include <stdio.h>
#define getch() getchar()
inline int F() {register int aa,bb,ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10+ch-'0'; return bb ? aa : -aa;
}
#define R register 
const int mod = 1000000;
const int Maxn = 100010;
int fa[Maxn] , c[Maxn][2] , root , tree[Maxn] , sz = 0;
  
void rotate(int&root , int x) {
    int y = fa[x] , z = fa[y] , p , q;
    if(c[y][0] == x) p = 0; else p = 1;
    q = p^1;
    if(y == root) root = x;
    else if(c[z][0] == y) c[z][0] = x;
         else c[z][1] = x;
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
}
void splay(int&root , int x) {
    int y , z;
    while(x != root) {
        y = fa[x] , z = fa[y];
        if(y != root)
            if((c[y][0] == x) ^ (c[z][0] == y)) rotate(root , x);
            else rotate(root , y);
        rotate(root , x);
    }
}
  
void ins(int k) {
    if(!root) {root = ++sz; fa[root] = 0; tree[sz] = k; return;}
    int x = root;
    while(1) {
        if(tree[x] > k) {
            if(c[x][0]) x = c[x][0];
            else {
                c[x][0] = ++sz;
                fa[sz] = x;
                tree[sz] = k;
                splay(root , sz);
                return ;
            }
        }
        else {
            if(c[x][1]) x = c[x][1];
            else {
                c[x][1] = ++sz;
                fa[sz] = x;
                tree[sz] = k;
                splay(root , sz);
                return ;
            }
        }
    }
}
void del(int x) {
    splay(root , x);
    int lc = c[x][0] , rc = c[x][1];
    if(!lc || !rc) root = lc+rc;
    else {
        while(c[rc][0]) rc = c[rc][0];
        splay(c[root][1] , rc);
        c[rc][0] = lc;
        fa[lc] = rc;
        root = rc;
    }fa[root] = 0;
}
  
int query2(int k) {
    int x = root , ret = -1;
    while(tree[x] != k) {
        if(tree[x]>k) {
            ret = x;
            if(c[x][0]) x = c[x][0];
            else return ret;
        }
        else {
            if(c[x][1]) x = c[x][1];
            else return ret;
        }
    }return x;
}
int query1(int k) {
    int x = root , ret = -1;
    while(tree[x] != k) {
        if(tree[x]>k) {
            if(c[x][0]) x = c[x][0];
            else return ret;
        }
        else {
            ret = x;
            if(c[x][1]) x = c[x][1];
            else return ret;
        }
    }return x;
}
  
int main() {
    int t = F() , flag , k , f , ans = 0;
    while(t--) {
        k = F();
        int ll = query1(k) , rr = query2(k);
        if(ll == -1) {
            ans += tree[rr] - k;
        }
        else if(rr == -1) {
            ans += k - tree[ll];
        }
        else {
            if(k - tree[ll] > tree[rr] - k) {
                ans += tree[rr] - k;
            }
            else {
                ans += k - tree[ll];
            }
        }
        ins(k);
    }printf("%d",ans);
}