#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
inline int F() {  register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 100005;
char a[Maxn] , b[Maxn];
int main() {
    scanf("%s",a+1);
    scanf("%s",b+1);
    int lena = strlen(a+1);
    int lenb = strlen(b+1);
    if(lena != lenb) {
        printf("%d\n",max(lena,lenb));
    }
    if(lena == lenb) {
        bool flag = 0;
        for(int i=1; i<=lena; ++i) {
            if(a[i] != b[i]) {
                flag = 1;
                break;
            }
        }
        if(flag) printf("%d\n",lena);
        else puts("-1");
    }
}