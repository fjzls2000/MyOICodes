/**************************************************************
    Problem: 2330
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:176 ms
    Memory:8828 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 200010;
const int Maxm = 400010;
int n , m , ecnt , to[Maxm] , next[Maxm] , g[Maxn] , w[Maxm] , dis[Maxn] , cir[Maxn] , h = 0 , t , now , q[Maxn];
bool inq[Maxn]; long long ans = 0;
void ins(int a , int b , int wi) {
    to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; w[ecnt] = wi;
}
bool spfa() {
    q[t = 1] = 0; inq[0] = cir[0] = 1;
    while(h != t) {
        now = q[++h]; if(h+1 == Maxn) h = 0;
        for(int i=g[now]; i; i=next[i]) {
            if (dis[to[i]] < dis[now] + w[i]) {
                dis[to[i]] = dis[now] + w[i];
                if(++cir[to[i]] >= n) return 0;
                if(!inq[to[i]]) {
                    q[++t] = to[i];
                    inq[to[i]] = 1;
                    if(t+1 == Maxn) t = 0;
                }
            }
        }
        inq[now] = 0;
    }
    return 1;
}
int main() {
    n = F() ; m = F();
    while(m--) {
        int flag = F() , a = F() , b = F();
        if(flag == 1) ins(a,b,0) , ins(b,a,0);
        if(flag == 2) if(a == b) {puts("-1"); return 0;} else ins(a,b,1);
        if(flag == 3) ins(b,a,0);
        if(flag == 4) if(a == b) {puts("-1"); return 0;} else ins(b,a,1);
        if(flag == 5) ins(a,b,0);
    }
    for(int i=n; i; --i) ins(0,i,1);
    if(!spfa()) {puts("-1"); return 0;}
    for(int i=1; i<=n; ++i) ans += dis[i];
    printf("%lld",ans);
}