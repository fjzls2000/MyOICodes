/**************************************************************
    Problem: 2733
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1860 ms
    Memory:25824 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
const int Maxt = 20 * Maxn;
int n , m , fa[Maxn] , root[Maxn] , val[Maxn] , id[Maxn] , c[Maxt][2] , sum[Maxt] , sz = 0;
int find(int x) { return fa[x] == x ? x : (fa[x] = find(fa[x])); }
void update(int x) { sum[x] = sum[c[x][0]] + sum[c[x][1]]; }
void insert(int&x , int l , int r , int val) {
    if(!x) x = ++sz;
    if(l == r) { sum[x] = 1; return; }
    int mid = (l + r) >> 1;
    if(val <= mid) insert(c[x][0],l,mid,val);
    else insert(c[x][1],mid+1,r,val);
    update(x);
}
int query(int x , int l , int r , int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(k <= sum[c[x][0]]) return query(c[x][0],l,mid,k);
    else return query(c[x][1],mid+1,r,k - sum[c[x][0]]);
}
int merge(int x , int y) {
    if(!x) return y;
    if(!y) return x;
    c[x][0] = merge(c[x][0],c[y][0]);
    c[x][1] = merge(c[x][1],c[y][1]);
    update(x);
    return x;
}
char op[2];
int main() {
    n = F() , m = F();
    for(int i=1; i<=n; ++i) val[i] = F();
    for(int i=1; i<=n; ++i) fa[i] = i;
    for(int i=1; i<=m; ++i) {
        int a = F() , b = F();
        if(find(a) == find(b)) continue;
        fa[find(a)] = find(b);
    }
    for(int i=1; i<=n; ++i) {
        insert(root[find(i)],1,n,val[i]);
        id[val[i]] = i;
    }
    int q = F();
    while(q--) {
        scanf("%s",op);
        int a = F() , b = F();
        if(op[0] == 'Q') {
            int p = find(a);
            if(sum[root[p]] < b) { puts("-1"); continue; }
            printf("%d\n",id[query(root[p],1,n,b)]);
        }
        else {
            int p = find(a) , q = find(b);
            if(p == q) continue;
            fa[p] = q;
            root[q] = merge(root[p],root[q]);
        }
    }
}