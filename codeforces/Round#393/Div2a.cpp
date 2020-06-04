#include <stdio.h>
int a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
    int n , m , now = 1;
    scanf("%d%d",&n,&m);
    for(int i=1; i<a[n]; ++i) {
        ++m;
        if(m > 7) m -= 7 , ++now;
    }printf("%d\n",now);
}