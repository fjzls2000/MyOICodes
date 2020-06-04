/**************************************************************
    Problem: 3212
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:48 ms
    Memory:12916 kb
****************************************************************/
 
#include <stdio.h>
inline int max(const int&a , const int&b) { return a > b ? a : b ; }
inline int min(const int&a , const int&b) { return a < b ? a : b ; }
const int MAXBUF = 1<<22; char B[MAXBUF] , *S = B , *T = B;
//#define getch() (S == T && (T = (S = B) + fread(B,1,MAXBUF,stdin) , S == T) ? EOF : *S ++)
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxt = 409601;
#define R register
int ll[Maxt] , rr[Maxt] , lazy[Maxt];
long long sum[Maxt];
void downpush(int x) {
    if(!lazy[x] || ll[x] == rr[x]) return;
    sum[x<<1] += (rr[x<<1] - ll[x<<1] + 1) * (long long) lazy[x];
    sum[x<<1|1] += (rr[x<<1|1] - ll[x<<1|1] + 1) * (long long) lazy[x];
    lazy[x<<1] += lazy[x];
    lazy[x<<1|1] += lazy[x];
    lazy[x] = 0;
}
void Build(R int x , R int l , R int r) {
    ll[x] = l; rr[x] = r;
    if(l == r) {
        sum[x] = F();
        return;
    }
    R int mid = (l+r) >> 1;
    Build(x<<1 , l , mid);
    Build(x<<1|1 , mid+1 , r);
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
void modify(int x , int l , int r , int val) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return;
    if(l == ll[x] && r == rr[x]) {
        sum[x] += (r-l+1) * (long long) val;
        lazy[x] += val;
        return;
    }
    modify(x<<1 , l , r , val); modify(x<<1|1 , l , r , val);
    sum[x] = sum[x<<1] + sum[x<<1|1];
}
long long query(int x , int l , int r) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return 0;
    if(l == ll[x] && r == rr[x]) return sum[x];
    else return query(x<<1 , l , r) + query(x<<1|1 , l , r);
}
int main() {
    R int n = F() , m = F() , ch;
    Build(1,1,n);
    while(m--) {
        while(ch = getch() , ch!='Q' && ch!='C');
        if(ch == 'Q') {
            R int l = F() , r = F();
            printf("%lld\n",query(1,l,r));
        }
        else {
            R int l = F() , r = F() , val = F();
            modify(1,l,r,val);
        }
    }
}