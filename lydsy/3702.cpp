/**************************************************************
    Problem: 3702
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8656 ms
    Memory:58648 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
inline long long min(register long long a , register long long b) { return a < b ? a : b ; }
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
#define ll long long
const int Maxt = 4000010;
const int Maxn = 400010;
int n , m , sz = 0 , c[Maxt][2] , v[Maxn] , seg = 0 , lc[Maxn] , rc[Maxn] , sum[Maxt] , root[Maxn];
ll cnt1 , cnt2 , ans = 0;
void init(int x) {
    v[x] = F();
    if(!v[x]) {
        lc[x]=++sz; init(lc[x]);
        rc[x]=++sz; init(rc[x]);
    }
}
void update(int x) { sum[x] = sum[c[x][0]] + sum[c[x][1]]; }
void Build(int&x , int l , int r , int val) {
    if(!x) x = ++seg;
    if(l == r) sum[x] = 1;
    else {
        int mid = (l + r) >> 1;
        if(val <= mid) Build(c[x][0] , l , mid , val);
        else Build(c[x][1] , mid+1 , r , val);
        update(x);
    }
}
int merge(int x , int y) {
    if(!x) return y;
    if(!y) return x;
    cnt1 += (ll)sum[c[x][1]]*sum[c[y][0]];
    cnt2 += (ll)sum[c[x][0]]*sum[c[y][1]];
    c[x][0] = merge(c[x][0] , c[y][0]);
    c[x][1] = merge(c[x][1] , c[y][1]);
    update(x);
    return x;
}
void Solve(int x) {
    if(!x) return ;
    Solve(lc[x]); Solve(rc[x]);
    if(!v[x]) {
        cnt1 = cnt2 = 0;
        root[x] = merge(root[lc[x]] , root[rc[x]]);
        ans += min(cnt1 , cnt2);
    }
}
int main() {
    n = F();
    init(++sz);
    for(int i=1; i<=sz; ++i)
        if(v[i]) Build(root[i] , 1 , n , v[i]);
    Solve(1);
    printf("%lld",ans);
}