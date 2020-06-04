#include <stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    if(n<3) { printf("0 %d",n); return 0; }
    int tmp = n%7 , ans1 = (n/7)*2;
    if(tmp == 6) ++ans1;
    int ans2 = 2; n-=2;
    tmp = n%7; ans2 += (n/7)*2;
    if(tmp == 6) ++ans2;
    printf("%d %d\n",ans1,ans2);
}