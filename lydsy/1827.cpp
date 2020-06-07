/**************************************************************
    Problem: 1827
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:268 ms
    Memory:9560 kb
****************************************************************/
 
#include <stdio.h>
#define ll long long
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100010;
const int Maxm = 200010;
int n , to[Maxm] , next[Maxm] , g[Maxn] , w[Maxm] , ecnt = 0;
ll ans , c[Maxn] , dis[Maxn] , size[Maxn];
void ins(int a , int b , int wi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi;
    to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; w[ecnt] = wi;
}
 
ll dfs(int x , int fa) {
    ll ans = dis[x] * c[x];
    size[x] = c[x];
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa) continue;
        dis[to[i]] = dis[x] + w[i];
        ans += dfs(to[i],x);
        size[x] += size[to[i]];
    }
    return ans;
}
 
void move(int x , int fa) {
    for(int i=g[x]; i; i=next[i]) {
        if(to[i] == fa) continue;
        if(size[1]-2*size[to[i]]<0) {
            ans = ans + (size[1]-2*size[to[i]])*w[i];
            move(to[i],x);
        }
    }
}
 
int main() {
    n = F();
    for(int i=1; i<=n; ++i)
        c[i] = F();
    for(int i=1; i<n; ++i) {
        int a = F() , b = F() , wi = F();
        ins(a,b,wi);
    }
    ans = dfs(1,0);
    move(1,0);
    printf("%lld",ans);
}