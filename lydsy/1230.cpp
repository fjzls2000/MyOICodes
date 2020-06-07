/**************************************************************
    Problem: 1230
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1520 ms
    Memory:11448 kb
****************************************************************/
 
#include <stdio.h>
#include <iostream>
using namespace std;
#define getch() getchar()
inline int F() { register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200010;
const int Maxt = 4*Maxn;
int n , m , flag , a , b , ll[Maxt] , rr[Maxt] , tree[Maxt];
bool rev[Maxt];
 
void downpush(int x) {
    if(ll[x] == rr[x]) return ;
    if(rev[x]) {
        rev[x<<1] ^= 1;
        rev[x<<1|1] ^= 1;
        tree[x<<1] = rr[x<<1] - ll[x<<1] + 1 - tree[x<<1];
        tree[x<<1|1] = rr[x<<1|1] - ll[x<<1|1] + 1 - tree[x<<1|1];
        rev[x] = 0;
        tree[x] = tree[x<<1] + tree[x<<1|1];
    }
}
 
void Build(int x , int l , int r) {
    ll[x] = l; rr[x] = r;
    if(l == r) return ;
    else {
        int mid = (l+r) >> 1;
        Build(x<<1 , l , mid);
        Build(x<<1|1 , mid+1 , r);
    }
}
 
int query(int x , int l , int r) {
    downpush(x);
    l = max(l , ll[x]); r = min(r , rr[x]);
    if(l > r) return 0;
    if(l == ll[x] && r == rr[x]) return tree[x];
    return query(x<<1 , l , r) + query(x<<1|1 , l , r);
}
 
void update(int x , int l , int r) {
    downpush(x);
    l = max(ll[x] , l); r = min(rr[x] , r);
    if(l > r) return ;
    if(l == ll[x] && r == rr[x]) {
        tree[x] = rr[x] - ll[x] + 1 - tree[x];
        rev[x] = 1;
        downpush(x);
    }
    else {
        update(x<<1 , l , r);
        update(x<<1|1 , l , r);
        tree[x] = tree[x<<1] + tree[x<<1|1];
    }
}
 
int main() {
    n = F(); m = F();
    Build(1,1,n);
    while(m--) {
        flag = F(); a = F(); b = F();
        if(flag) {
            printf("%d\n" , query(1 , a , b));
        }
        else {
            update(1 , a , b);
        }
    }
}