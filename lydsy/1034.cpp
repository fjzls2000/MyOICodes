/**************************************************************
    Problem: 1034
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:252 ms
    Memory:1512 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
const int Maxn = 100010;
int n ;
int cmp(int *a , int *b) {
    int h1 = 1 , h2 = 1 , t1 = n , t2 = n , ans = 0;
    while(h1<=t1 && h2<=t2) {
        if(a[h1] > b[h2]) {ans+=2;h1++;h2++;}
        else if(a[t1] > b[t2]) {ans+=2;t1--;t2--;}
        else {
            if(a[t1] == b[h2]) ans++;
            t1--; h2++;
        }
    }return ans;
}bool c(int a , int b) {return a>b;}
int main() {
    int a[Maxn] , b[Maxn];
    /*Init*/
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d",&b[i]);
    std::sort(a+1,a+n+1,c);
    std::sort(b+1,b+n+1,c);
    /*Solve*/
    printf("%d %d",cmp(a,b),(n<<1)-cmp(b,a));
}