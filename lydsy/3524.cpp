/**************************************************************
    Problem: 3524
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:6192 ms
    Memory:123860 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
const int Maxn = 500010;
const int Maxt = 20*Maxn;
 
int n , m , in[Maxn] , c[Maxt][2] , tree[Maxt] , top[Maxn] , tcnt = 0 , X[Maxn];
 
void unique() {
    m = 1;
    for(int i=2; i<=n; i++)
        if(X[i] != X[m]) X[++m] = X[i];
}
 
int Search(int x) {
    int mid , l = 1 , r = m;
    while(l<r) {
        mid = (l+r+1)>>1;
        if(X[mid] > x) r = mid-1;
        else l = mid;
    }return l;
}
 
void update(int x , int l , int r , int p) {
    tree[++tcnt] = tree[x] + 1;
    if(l == r) return;
    int mid = (l+r) >> 1;
    if(mid >= p) {c[tcnt][1] = c[x][1]; c[tcnt][0] = tcnt+1; update(c[x][0],l,mid,p);}
    else{c[tcnt][0] = c[x][0]; c[tcnt][1] = tcnt+1; update(c[x][1],mid+1,r,p);}
}
 
int query(int a , int b , int l , int r , int k , int cmp) {
    if(l == r) if(tree[b] - tree[a] > cmp) return l; else return 0;
     
    int tmp = tree[c[b][0]] - tree[c[a][0]];
    int mid = (l+r)>>1;
     
    if(tmp >= k) return query(c[a][0],c[b][0],l,mid,k,cmp);
    else return query(c[a][1],c[b][1],mid+1,r,k-tmp,cmp);
}
 
int main() {
    int t , tl , tr;
    scanf("%d%d",&n,&t);
    for(int i=1; i<=n; i++)
        scanf("%d",&in[i]) , X[i] = in[i];
    std::sort(X+1,X+n+1);
    unique();
    for(int i=1; i<=n; i++) {
        in[i] = Search(in[i]);
        top[i] = tcnt+1;
        update(top[i-1],1,m,in[i]);
    }
    while(t--) {
        scanf("%d%d",&tl,&tr);
        if(tl == tr) { printf("%d\n",X[in[tl]]); continue;}
        int tmp = query(top[tl-1],top[tr],1,m,(tr-tl+3)>>1,(tr-tl+1)>>1);
        if(tmp) printf("%d\n",X[tmp]);
        else puts("0");
    }
}