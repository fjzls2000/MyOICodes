/**************************************************************
    Problem: 1862
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1292 ms
    Memory:58684 kb
****************************************************************/
 
#include <stdio.h>
#include <string.h>
#define inf 233333333
inline int min(register int a , register int b) { return a < b ? a : b ; }
#define getch() getchar()
 
namespace Trie{
    const int Maxn = 450010;
    int Trie[Maxn] , g[Maxn][26] , fa[Maxn] , sz = 0 , lazy[Maxn] , id[Maxn] , Tsz = 0;
    int find(char *s) {
        int x = 0 , i = 0 , len = strlen(s+1);
        while(++i<=len) {
            if(!g[x][s[i]-'A']) g[x][s[i]-'A'] = ++Tsz , fa[Tsz] = x , Trie[Tsz] = s[i];
            x = g[x][s[i]-'A'];
        }
        if(lazy[x]) return lazy[x];
        lazy[x] = ++sz;
        id[sz] = x;
        return 0;
    }
}
 
#define R register 
const int Maxn = 250010;
int root , n , otop = 0 , size[Maxn] , c[Maxn][2] , num[Maxn] , fa[Maxn] , output[30];
char s[Maxn];
 
void update(int x) { size[x] = size[c[x][0]] + size[c[x][1]] + 1; }
void clean(int x , int k) {
    num[x] = k;
    c[x][0] = c[x][1] = fa[x] = 0;
    size[x] = 1;
}
 
void rotate(int&root , int x) {
    int y = fa[x] , z = fa[y] , p,q;
    if(x == c[y][0]) p = 0; else p = 1;
    q = p^1;
    if(y == root) root = x;
    else
        if(y == c[z][0]) c[z][0] = x;
        else c[z][1] = x;
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
    update(y); update(x);
}
void splay(int&root , int x) {
    int y , z;
    if(!root) root = x;
    while(root != x) {
        y = fa[x]; z = fa[y];
        if(y != root) {
            if((c[y][0] == x) ^ (c[z][0] == y)) rotate(root , x);
            else rotate(root , y);
        }rotate(root , x);
    }
}
 
void insert(int x , int k) {
    clean(x , k);
    if(!root) {root = x;return;}
    int now = root , f = 1;
    while(f) {
        ++size[now];
        if(num[now]<=k) {
            if(c[now][1]) now = c[now][1];
            else f = 0 , c[now][1] = x , fa[x] = now;
        }
        else {
            if(c[now][0]) now = c[now][0];
            else f = 0 , c[now][0] = x , fa[x] = now;
        }
    }splay(root , x);
}
void del(int x) {
    splay(root , x);
    if(!c[x][0]&&!c[x][1]) root = 0;
    else if(c[x][0] && !c[x][1])fa[c[x][0]] = 0 , root = c[x][0];
    else if(c[x][1] && !c[x][0])fa[c[x][1]] = 0 , root = c[x][1];
    else {
        int y = c[x][0];
        while(c[y][1]) y = c[y][1];
        splay(c[x][0] , y);
        c[y][1] = c[x][1];
        fa[y] = 0;
        fa[c[x][1]] = y;
        root = y;
        update(y);
    }
}
void Kth(int k) {
//  printf("rt = %d\n",root);
//  for(int i=1; i<=Trie::sz; ++i) printf("ID:%d , %c , fa[i]=%d , lc:%d rc:%d num:%d size:%d\n",i , Trie::Trie[Trie::id[i]] , fa[i],c[i][0],c[i][1] , -num[i] , size[i]);
    int now = root , p , t = 0;
    while(now) {
//      printf("!now = %d!\n",now);
        p = size[c[now][0]];
        if(p + 1 == k) break;
        if(k<=p) now = c[now][0];
        else now = c[now][1] , k -= p+1;
    }
    splay(root , now);
    now = Trie::id[now];
    while(now) output[++otop] = Trie::Trie[now] , now = Trie::fa[now];
    while(otop) printf("%c",output[otop--]);
}
int rank(int x) {
    splay(root , x);
    return size[c[x][0]] + 1;
}
int main() {
    scanf("%d",&n);
    int x , y , ch;
    while(n--) {
        x = 0;
        while(ch = getch() , ch != '+' && ch != '?');
        if(ch == '+') {
            scanf("%s%d",s+1,&x);
            x = -x;
            y = Trie::find(s);
            if(y) del(y) , insert(y , x);
            else insert(Trie::sz , x);
        }
        else {
            scanf("%s",s+1);
            if(s[1] >= '0' && s[1] <= '9') {
                int len = strlen(s+1);
                for(int i=1; i<=len; ++i) x = x*10+s[i]-'0';
                int y = min(x+9,Trie::sz);
                for(int i=x; i<=y; ++i)
                    Kth(i),printf("%c" , i == y ? '\n' : ' ');
            }
            else
                printf("%d\n",rank(Trie::find(s)));
        }
//      for(int i=1; i<=Trie::sz; ++i) printf("ID:%d , %c , fa[i]=%d , lc:%d rc:%d num:%d size:%d\n",i , Trie::Trie[Trie::id[i]] , fa[i],c[i][0],c[i][1] , -num[i] , size[i]);
    }
}