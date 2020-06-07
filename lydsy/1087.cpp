/**************************************************************
    Problem: 1087
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:28 ms
    Memory:5080 kb
****************************************************************/
 
#include <stdio.h>
#define ll long long
inline int F() {register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int n , m , ed , cnt[512];
ll f[10][100][512];
bool c1[512],c2[512][512];
void pre() {
    int s;
    for(int i=0; i<=ed; ++i)
        if((i&(i>>1)) == 0) {
            s = 0;
            for(int x=i; x; x>>=1) s+=(x&1);
            cnt[i] = s; c1[i] = 1;
        }
    for(int i=0; i<=ed; ++i)
        if(c1[i])
            for(int j=0; j<=ed; ++j)
                if(c1[j])
                    if( (i&j) == 0 && (i&(j>>1)) == 0 && (j&(i>>1)) == 0)
                        c2[i][j] = 1;
}
int main() {
    n = F(); m = F();
    ed = (1<<n)-1;
    pre();
    for(int i=0; i<=ed; ++i) if(c1[i]) f[1][cnt[i]][i] = 1;
    for(int j=1; j<n; ++j)
        for(int k=0; k<=ed; ++k) if(c1[k])
            for(int i=0; i<=ed; ++i) if(c1[i])
                if(c2[k][i])
                    for(int p=cnt[k]; p+cnt[i]<=m; ++p)
                        f[j+1][p+cnt[i]][i]+=f[j][p][k];
    ll ans = 0;
    for(int i=0; i<=ed; ++i)
        ans += f[n][m][i];
    printf("%lld",ans);
}