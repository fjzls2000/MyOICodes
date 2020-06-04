#include <stdio.h>
const int Maxn = 110;
int a[Maxn] , b[Maxn] , n , L;
int main() {
    scanf("%d%d",&n,&L);
    for(int i=1; i<=n; ++i) {
        scanf("%d",&a[i]);
        a[i+n] = a[i]+L;
    }
    for(int i=1; i<=n; ++i) {
        scanf("%d",&b[i]);
        b[i+n] = b[i]+L;
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            int cnt = 0;
            for(int k=0; k<n; ++k)
                if((a[i+k] - a[i]) == (b[j+k] - b[j]))
                    ++cnt;
            if(cnt == n) {
                puts("YES");
                return 0;
            }
        }
    }puts("NO");
}