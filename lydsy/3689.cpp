/**************************************************************
    Problem: 3689
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:780 ms
    Memory:133636 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 1000010;
int n , m , bin[32] , a[Maxn] , b[Maxn] , tmp[32][Maxn] , num = 0;
long long cnt[32];
void cal(int l , int r , int k) {
    if(l >= r) return;
    int tot = 0;
    for(int i=l; i<=r; ++i)
        if(tmp[k+1][i]&bin[k]) ++tot;
    int L = l-1 , R = l+tot-1;
    for(int i=l; i<=r;++i)
        if(tmp[k+1][i]&bin[k]) tmp[k][++L] = tmp[k+1][i];
        else tmp[k][++R] = tmp[k+1][i];
    if(k != 0) { cal(l,l+tot-1,k-1); cal(l+tot,r,k-1); }
    cnt[k] += (long long)(r-l+1)*(r-l)/2;
}
void print(int l , int r , int k , int x) {
    if(l >= r) return;
    if(k == x) {
        for(int i=l; i<r; ++i)
            for(int j=i+1; j<=r; ++j)
                b[++num] = tmp[x+1][i]^tmp[x+1][j];
    }
    else {
        int tot = 0;
        for(int i=l; i<=r; ++i)
            if(tmp[k+1][i]&bin[k]) ++tot;
        if(k != 0) print(l,l+tot-1,k-1,x) , print(l+tot,r,k-1,x);
    }
}
void Solve() {
    for(int i=1; i<=n; ++i) tmp[31][i] = a[i];
    cal(1,n,30);
    bool flag = 0;
    for(int i=30; i>=0; --i)
        if(cnt[i] < m) { print(1,n,30,i+1); flag = 1; break; }
    if(!flag) print(1,n,30,0);
    std::sort(b+1,b+num+1);
    for(int i=1; i<=m; ++i) printf("%d ",b[i]);
}
int main() {
    bin[0] = 1;for(int i=1; i<=31; ++i) bin[i] = bin[i-1]<<1;
    n = F(); m = F();
    for(int i=1; i<=n; ++i)
        a[i] = F();
    Solve();
}