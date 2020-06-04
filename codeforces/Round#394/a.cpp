#include <stdio.h>
#include <iostream>
using std::swap;
int main() {
    int a , b;
    scanf("%d%d",&a,&b);
    if(a < b) swap(a,b);
    if(a-b <= 1 && !(a == 0 && b == 0)) puts("YES");
    else puts("NO");
}