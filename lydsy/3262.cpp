/**************************************************************
    Problem: 3262
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:3552 ms
    Memory:3936 kb
****************************************************************/
 
/*陌上花开 三维求比自己小的个数*/
#include <stdio.h>
#include <algorithm>
const int Maxn = 100010;
const int MaxK = 200010;
int N , K , f[Maxn] , tree[MaxK] ;
struct point {
    int s , c , m , i , sum;
} a[Maxn] ;
/*tools*/
int lowbit(int x) {return (x)&(-x);}
bool cmps(point a , point b ) {return a.s == b.s ? ( a.c == b.c ? a.m < b.m : a.c < b.c) : a.s < b.s;}
bool cmpc(point a , point b ) {return a.c == b.c ? ( a.m == b.m ? a.s < b.s : a.m < b.m) : a.c < b.c;}
bool operator == (point a , point b) {return a.m == b.m && a.c == b.c && a.s;}
/*tree*/
void update(int x , int y) {for(; x <= K; x += lowbit(x)) tree[x]+=y;}
int query(int x) {
    int ans = 0;
    for(; x ; x -= lowbit(x)) ans += tree[x];
    return ans;
}
/*Solve Problem*/
void Solve(int l , int r) {
    if( l == r ) return ;
     
    int mid = (l + r) >> 1;
    Solve( l , mid);
    Solve( mid+1 , r);
    std::sort( a+l , a+mid+1 , cmpc);
    std::sort( a+mid+1 , a+r+1 , cmpc);
    int i = l , j = mid;
     
    while(++j<=r) {
        while(i<=mid && a[i].c <= a[j].c)
            update(a[i++].m,a[i].sum);
        f[a[j].i] += query(a[j].m);
    }
    for(--i; i>=l; i--)
        update(a[i].m,-a[i].sum);
}
int main() {
    int n = 0;
    /*Init*/
    scanf("%d%d" , &N , &K );
    for(int i=1; i<=N; i++)
        scanf("%d%d%d" , &a[i].s ,  &a[i].c ,  &a[i].m ) , a[i].i = i;
    std::sort( a+1 , a+N+1 , cmps);
    for(int i=1; i<=N; i++) {
        if(a[i] == a[i-1])
            a[n].sum++;
        else a[++n] = a[i];
    }
    for(int i=1; i<=n; i++) a[i].sum++;
    /*Solve*/
    Solve( 1 , n );
    /*End*/
    for(int i=0; i<n; i++) tree[i] = 0;
    for(int i=1; i<=n; i++)
        tree[f[a[i].i]+a[i].sum-1]+=a[i].sum;
    for(int i=0; i<N; i++)
        printf("%d\n",tree[i]);
    return 0;
}