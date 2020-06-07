/**************************************************************
    Problem: 1202
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:220 ms
    Memory:808 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 101;
int n , m;
int f[Maxn] , g[Maxn];
 
int find(int x) {
    if(f[x] == x) return x;
    int old = f[x];
    f[x] = find(f[x]);
    g[x] += g[old];
    return f[x];
}
bool tryy(int a , int b , int c) {
    int fa = find(a) , fb = find(b);
    if( fa == fb ) return g[a]-g[b] == c ;
    else {
        f[fa] = fb;
        g[fa] += c+g[b]-g[a];
    }return 1;
}
void Solve() {
    bool flag = 1; int x , y , z;
    scanf("%d%d",&n,&m);
    for(int i=0; i<=n; i++)
        (g[i] = 0) , f[i] = i;
    while(m--) {
        scanf("%d%d%d",&x,&y,&z);
        if(!tryy(x-1,y,z)) {while(m--) scanf("%d%d%d",&x,&y,&z);puts("false"); return;}
    }puts("true");
}
 
int main() {
    int t;scanf("%d",&t);
    while(t--) Solve();
}