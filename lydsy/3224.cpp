/**************************************************************
    Problem: 3224
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:444 ms
    Memory:28356 kb
****************************************************************/
 
#include <stdio.h>
 
const int MAXBUF = 1<<22; char B[MAXBUF] , *S = B , *T = B;
//#define getch() (S == T && (T = (S = B) + fread(B,1,MAXBUF,stdin) , S == T) ? EOF : *S ++)
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 1000010;
int c[Maxn][2] , fa[Maxn] , w[Maxn] , v[Maxn] , size[Maxn] , sz = 0 , root = 0;
 
void update(int x) { size[x] = size[c[x][0]] + size[c[x][1]] + w[x]; }
 
void rotate(int x , int&root) {
    int y = fa[x] , z = fa[y] , p,q;
    if(x == c[y][0]) p = 0; else p = 1;
    q = p ^ 1;
    if(y == root) root = x;
    else {
        if(y == c[z][0]) c[z][0] = x;
        else c[z][1] = x;
    }
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
    update(x); update(y);
}
void splay(int x , int&root){
    int y , z;
    while(x != root) {
        y = fa[x] , z = fa[y];
        if(y != root) {
            if( (y == c[z][0]) ^ (x == c[y][0]) ) rotate(y,root);
            else rotate(x,root);
        }rotate(x,root);
    }
}
 
void insert(int k) {
    if(!root) { root = ++sz; w[sz] = size[sz] = 1; v[sz] = k; fa[sz] = c[sz][0] = c[sz][1] = 0; return; }
    int x = root;
    while(v[x] != k) {
        ++size[x];
        if(k < v[x]) {
            if(c[x][0]) x = c[x][0];
            else {
                c[x][0] = ++sz;
                w[sz] = size[sz] = 1;
                v[sz] = k;
                fa[sz] = x;
                c[sz][0] = c[sz][1] = 0;
                splay(sz,root);
                return;
            }
        }
        else {
            if(c[x][1]) x = c[x][1];
            else {
                c[x][1] = ++sz;
                w[sz] = size[sz] = 1;
                v[sz] = k;
                fa[sz] = x;
                c[sz][0] = c[sz][1] = 0;
                splay(sz,root);
                return;
            }
        }
    }
    ++w[x];
    ++size[x];
    splay(x,root);
}
 
void rec(int x) {
    splay(x,root);
    if(!c[x][0]) {root = c[x][1]; fa[c[x][1]] = 0; update(c[x][1]); return;}
    if(!c[x][1]) {root = c[x][0]; fa[c[x][0]] = 0; update(c[x][0]); return;}
    int y = c[x][0] , z = c[x][1];
    while(c[y][1]) y = c[y][1];
    while(c[z][0]) z = c[z][0];
    splay(y,root);
    splay(z,c[root][1]);
    c[z][0] = 0;
    fa[x] = 0;
    update(z);
    update(y);
}
 
void del(int k) {
    if(size[root] == 1) { root = 0; return; }
    int x = root;
    while(v[x] != k) {
        --size[x];
        if(k < v[x]) x = c[x][0];
        else x = c[x][1];
    }--w[x];
    --size[x];
    splay(x , root);
    if(!w[x]) rec(x);
}
 
int findrk(int x , int k) {
    if(v[x] == k) return size[c[x][0]] + 1;
    if(k < v[x]) return findrk(c[x][0] , k);
    else return size[c[x][0]] + w[x] + findrk(c[x][1] , k);
}
 
int findnum(int x , int k) {
    int y = c[x][0];
    if(size[y] < k && k <= size[y]+w[x]) return v[x];
    if(k <= size[y]) return findnum(y,k);
    else return findnum(c[x][1] , k-size[y]-w[x]);
}
 
int search1(int k) {
    int x = root , ans = 0;
    while(1) {
        if(k <= v[x]) {
            if(c[x][0]) x = c[x][0];
            else return ans;
        }
        else {
            ans = v[x];
            if(c[x][1]) x = c[x][1];
            else return ans;
        }
    }return ans;
}
 
int search2(int k) {
    int x = root , ans = 0;
    while(1) {
        if(k < v[x]) {
            ans = v[x];
            if(c[x][0]) x = c[x][0];
            else return ans;
        }
        else {
            if(c[x][1]) x = c[x][1];
            else return ans;
        }
    }return ans;
}
 
int main() {
    int m = F();
    while(m--) {
        int opt = F() , x = F();
        if(opt == 1) insert(x);
        if(opt == 2) del(x);
        if(opt == 3) printf("%d\n" , findrk(root , x));
        if(opt == 4) printf("%d\n" , findnum(root , x));
        if(opt == 5) printf("%d\n" , search1(x));
        if(opt == 6) printf("%d\n" , search2(x));
    }
}