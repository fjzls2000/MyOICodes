/**************************************************************
    Problem: 1622
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:692 ms
    Memory:1900 kb
****************************************************************/
 
#include <stdio.h>
#include <string.h>
 
#define getch() getchar()
inline int F() {register int aa , bb , ch;
    while(ch = getch() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getch() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
 
const int Maxn = 1001;
const int Maxl = 101;
int n , m , ans;
char a[Maxn][Maxn] , b[Maxn][Maxl];
 
inline bool equ(char a , char b) {
    return ((a>='A'&&a<='Z') ? a-'A'+'a' : a) == ((b>='A'&&b<='Z') ? b-'A'+'a' : b);
}
 
bool jud(int x , int y) {
    int l1 = strlen(a[x]+1) , l2 = strlen(b[y]+1) , now = 1;
    for(int i=1; i<=l1; ++i) {
        if(equ(a[x][i] , b[y][now])) ++now;
    }
    return now == l2 + 1;
}
 
void Solve(int x) {
    ans = 0;
    for(int i=1; i<=m; ++i)
        if(jud(x , i)) ++ans;
}
 
int main() {
    n = F(); m = F();
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=m;i++)
        scanf("%s",b[i]+1);
    for(int i=1; i<=n; ++i) {
        Solve(i);
        printf("%d\n",ans);
    }
}