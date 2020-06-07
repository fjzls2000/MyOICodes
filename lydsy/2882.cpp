/**************************************************************
    Problem: 2882
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:524 ms
    Memory:1976 kb
****************************************************************/
 
//最小表示法裸题 
#include <stdio.h>
#include <algorithm>
using std::min;
const int Maxn = 300010;
int n , a[Maxn];
 
int main() {
     scanf("%d",&n);
     for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    int i = 0 , j = 1 , k = 0;
    while(i <= n && j <= n && k <= n) {
        int tmp = a[(i+k)%n] - a[(j+k)%n];
        if(tmp == 0) k++;
        else {
            if(tmp > 0)
                i += k + 1;
            else
                j += k + 1;
            if(i == j)
                j++;
            k = 0;
        }
    } j = min(i , j);
    for(i = j; i < n ; i++) printf("%d ",a[i]);
    for(i = 0; i < j-1 ; i++) printf("%d ",a[i]);
    printf("%d",a[j-1]);
}