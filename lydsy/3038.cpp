/**************************************************************
    Problem: 3038
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1372 ms
    Memory:7476 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#include <math.h>
inline long long max(long long a , long long b) { return a > b ? a : b ; }
inline long long min(long long a , long long b) { return a < b ? a : b ; }
inline long long F() {register long long aa ; int bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 400020;
int n , m , ll[Maxn] , rr[Maxn];
bool flag[Maxn];
long long sum[Maxn];
void Build(int x , int l , int r) {
    ll[x] = l , rr[x] = r;
    if(l == r) {
        sum[x] = F();
        flag[x] = (sum[x] == 1 || sum[x] == 0);
    }
    else {
        int mid = (l + r) >> 1;
        Build(x<<1 , l , mid);
        Build(x<<1|1 , mid+1 , r);
        sum[x] = sum[x<<1] + sum[x<<1|1];
        flag[x] = (flag[x<<1]&flag[x<<1|1]);
    }
}
 
void modify(int x , int l , int r) {
    l = max(l , ll[x]); r = min(r , rr[x]);
//  printf("***modify : x:%d(%d) , ll:%d,rr:%d , l = %d , r = %d\n",x,flag[x],ll[x],rr[x],l,r);
    if(l > r || flag[x]) return;
    if(ll[x] == rr[x]) {
        sum[x] = (long long)sqrt(sum[x]);
        if(sum[x] == 0 || sum[x] == 1) flag[x] = 1;
    }
    else {
        modify(x<<1 , l , r);
        modify(x<<1|1 , l , r);
        sum[x] = sum[x<<1] + sum[x<<1|1];
        flag[x] = (flag[x<<1]&flag[x<<1|1]);
    }
}
 
long long query(int x , int l , int r) {
    l = max(l , ll[x]); r = min(r , rr[x]);
    if(l > r) return 0;
    if(l == ll[x] && r == rr[x]) return sum[x];
    else return query(x<<1 , l , r) + query(x<<1|1 , l , r);
}
 
int main() {
    n = F();
    Build(1 , 1 , n);
    int t = F();
    while(t--) {
//      for(int i=1; i<=n; ++i) printf("!%d ",query(1,i,i)); puts("");
        int fl = F() , x = F() , y = F();
        if(x > y) { int tmp = x; x = y; y = tmp; }
//      printf("%d %d\n",x,y);
        if(fl) printf("%lld\n",query(1,x,y));
        else modify(1,x,y);
    }
}