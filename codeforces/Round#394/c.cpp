#include <stdio.h>
#define inf 233333333
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 51;
const int Maxm = 51;
int n , m , d[Maxn][3] , mn[3][3];
char a[Maxn][Maxn];
inline bool isdigit(char x) { return x>='0'&&x<='9'; }
int main() {
    n = F() , m = F();
    for(int i=1; i<=n; ++i)
        scanf("%s",a[i]+1);
    for(int i=1; i<=n; ++i) {
        d[i][0] = d[i][1] = d[i][2] = inf;
        for(int j=1; j<=m; ++j) {
            if(isdigit(a[i][j])) {
                if(d[i][0] > j-1) d[i][0] = j-1;
                if(d[i][0] > m-j+1) d[i][0] = m-j+1;
            }
            else if(a[i][j] == '#' || a[i][j] == '*' || a[i][j] == '&') {
                if(d[i][1] > j-1) d[i][1] = j-1;
                if(d[i][1] > m-j+1) d[i][1] = m-j+1;
            }
            else {
                if(d[i][2] > j-1) d[i][2] = j-1;
                if(d[i][2] > m-j+1) d[i][2] = m-j+1;
            }
        }
    }
    d[0][0] = d[0][1] = d[0][2] = inf;
    for(int i=0; i<3; ++i) {
        for(int j=1; j<=n; ++j) {
            if(d[mn[i][2]][i] > d[j][i]) {
                if(d[mn[i][1]][i] > d[j][i]) {
                    if(d[mn[i][0]][i] > d[j][i]) {
                        mn[i][2] = mn[i][1];
                        mn[i][1] = mn[i][0];
                        mn[i][0] = j;
                    }
                    else {
                        mn[i][2] = mn[i][1];
                        mn[i][1] = j;
                    }
                }
                else mn[i][2] = j;
            }
        }
    }
    int ans = inf;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            for(int k=0; k<3; ++k) {
                int a = mn[0][i] , b = mn[1][j] , c = mn[2][k];
                if(a != b && b != c && c != a) {
                    if(ans > d[a][0] + d[b][1] + d[c][2]) ans = d[a][0] + d[b][1] + d[c][2];
                }
            }
    printf("%d\n",ans );
}