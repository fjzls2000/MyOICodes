/**************************************************************
    Problem: 1028
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:312 ms
    Memory:828 kb
****************************************************************/
 
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 401;
int n , m , cnt[Maxn] , ans[Maxn] , tmp[Maxn];
bool check() {
    for(int i=1; i<=n; ++i) {
        if(cnt[i] >= 2) {
            for(int j=1; j<=n+2; ++j) tmp[j] = cnt[j];
            tmp[i] -= 2;
            int flag = 1;
            for(int j=1; j<=n+2; ++j) {
                if(tmp[j] < 0) {flag = 0; break;}
                tmp[j] %= 3;
                tmp[j+1] -= tmp[j];
                tmp[j+2] -= tmp[j];
            }
            if(flag) return 1;
        }
    }
    return 0;
}
int main() {
    n = F() , m = F();
    for(int i=1; i<=m+m+m+1; ++i) ++cnt[F()];
    for(int i=1; i<=n; ++i) {
        ++cnt[i];
        if(check()) ans[++ans[0]] = i;
        --cnt[i];
    }
    if(ans[0]) {for(int i=1; i<ans[0]; ++i) printf("%d ",ans[i]); printf("%d",ans[ans[0]]);} 
    else printf("NO");
}