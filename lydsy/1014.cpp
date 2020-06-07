/**************************************************************
    Problem: 1014
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8948 ms
    Memory:4060 kb
****************************************************************/
 
#include <stdio.h>
#include <string.h>
inline int min(register int a , register int b) { return a > b ? b : a ; }
#define inf 233333333
typedef long long ll;
const int mod = 9875321;
const int Maxn = 100010;
#define getch() getchar()
inline int F() {register int aa , ch;
    while(ch = getch() , ch<'0'||ch>'9'); aa = ch-'0';
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10+ch-'0';
    return aa;
}
#define R register
int size[Maxn] , fa[Maxn] , c[Maxn][2] , h[Maxn] , p[Maxn] , tree[Maxn] , litter[Maxn] , ltop = 0  , sz = 0 , n , root;
char ch[Maxn];
 
inline void update(R int x) {
    R int lc = c[x][0] , rc = c[x][1];
    size[x] = size[lc] + size[rc] + 1;
    h[x] = h[lc] + (ll)tree[x]*p[size[lc]]%mod + (ll)h[rc]*p[size[lc]+1]%mod;
    h[x] %= mod;
}
inline void downpush(R int x) { }
 
inline void rotate(int&root , R int x) {
    R int y = fa[x] , z = fa[y] , p , q;
    if(c[y][0] == x) p = 0 ; else p = 1;
    q = p^1;
    if(y == root) root = x;
    else {
        if(y == c[z][0]) c[z][0] = x;
        else c[z][1] = x;
    }
    fa[x] = z; fa[y] = x; fa[c[x][q]] = y;
    c[y][p] = c[x][q]; c[x][q] = y;
    update(y); update(x);
}
inline void splay(int&root , R int x) {
    R int y , z;
    while(x != root) {
        y = fa[x]; z = fa[y];
        if(y != root)
            if((c[y][0] == x) ^ (c[z][0] == y)) rotate(root , x);
            else rotate(root , y);
        rotate(root , x);
    }
}
 
inline int find(R int x , R int k) {
    downpush(x);
    R int y = c[x][0]; 
    if(size[y] + 1 == k) return x;
    if(size[y] >= k) return find(y , k);
    return find(c[x][1] , k - size[y] - 1);
}
 
inline void Build(R int l , R int r , int&now , R int lst) {
    if(l > r) return ;
    if(!now) {
        if(ltop) now = litter[--ltop];
        else now = ++sz;
    }
    R int mid = (l + r) >> 1;
    tree[now] = ch[mid] - 'a';
    fa[now] = lst; size[now] = 1;
    Build(l , mid-1 , c[now][0] , now);
    Build(mid+1 , r , c[now][1] , now);
    update(now);
}
 
inline int query(R int l , R int len) {
    R int x = find(root , l);
    splay(root , x);
    x = find(root , l+len+1);
    splay(c[root][1] , x);
    return h[c[x][0]];
}
 
inline int Solve(R int x , R int y) {
    R int l = 0 , r = min(sz - x , sz - y)-1 , ans = 0 , mid;
    while(l<=r) {
        mid = (l+r) >> 1;
        if(query(x , mid) == query(y , mid)) ans = mid , l = mid + 1;
        else r = mid-1;
    }return ans;
}
 
void Init() {
    p[0] = 1;
    for(R int i=1; i<Maxn; ++i) p[i] = (p[i-1]*27)%mod;
    scanf("%s",ch+2);
    n = strlen(ch+2)+2;
    Build(1 , n , root , 0);
}
 
int main() {
    Init();
    R int T , x , y; R char s[2],d[2];
//  for(int i=1; i<=n; ++i) printf("%d %d %d %d\n", i , tree[i] , c[i][0] , c[i][1]);
    T = F();
    while(T--) {
        scanf("%s",s+1);
        if(s[1] == 'Q') {
            x = F(); y = F();
            printf("%d\n",Solve(x,y));
        }
        if(s[1] == 'R') {
            x = F();
            scanf("%s",d+1);
            y = find(root , x+1);
            splay(root , y);
            tree[y] = d[1]-'a';
            update(y);
        }
        if(s[1] == 'I') {
            x = F();
            scanf("%s",ch+1);
            y = find(root , x+1);
            splay(root , y);
            y = find(root , x+2);
            splay(c[root][1] , y);
            Build(1 , 1 , c[y][0] , y);
            update(y); update(root);
        }
    }
}
/*
madamimadam
7
I 10 a
Q 1 7
Q 4 8
Q 10 11
Q 1 7
Q 2 11
*/