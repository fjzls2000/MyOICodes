/**************************************************************
    Problem: 1699
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1860 ms
    Memory:16912 kb
****************************************************************/
 
#include <iostream>
#include <stdio.h>
using namespace std;
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxt = 1000010;
int n , m , ll[Maxt] , rr[Maxt] , mn[Maxt] , mx[Maxt] ;
 
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r;
    if(l == r) {
        mx[x] = mn[x] = F();
    }
    else {
        int mid = (l + r) >> 1;
        Build(x<<1 , l , mid);
        Build(x<<1|1 , mid+1 , r);
        mx[x] = max(mx[x<<1] , mx[x<<1|1]);
        mn[x] = min(mn[x<<1] , mn[x<<1|1]);
    }
}
 
int querymx(int x , int l , int r) {
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return 0;
    if(ll[x] == l && r == rr[x]) return mx[x];
    else return max(querymx(x<<1 , l , r) , querymx(x<<1|1 , l , r));
}
 
int querymn(int x , int l , int r) {
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return 2147483647;
    if(ll[x] == l && r == rr[x]) return mn[x];
    else return min(querymn(x<<1 , l , r) , querymn(x<<1|1 , l , r));
}
 
int main() {
    cin>>n>>m;
    Build(1 , 1 , n);
    while(m--) {
        int a = F() , b = F();
        printf("%d\n",querymx(1 , a , b) - querymn(1 , a , b));
    }
}