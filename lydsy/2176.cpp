/**************************************************************
    Problem: 2176
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1624 ms
    Memory:39868 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
using std::min;
const int Maxn = 10000010;
int a[Maxn];
int main() {
    int n , ch;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        while(ch=getchar() , ch<33 || ch>254);
        a[i] = ch;
    }
    int i = 0 , j = 1 , k = 0;
    while( i < n && j < n && k < n ) {
        int tmp = a[(i+k)%n] - a[(j+k)%n];
        if(tmp == 0) k++;
        else {
            if(tmp > 0) i += k+1;
            else j += k+1;
            if(i == j)
                j++;
            k = 0;
        }
    }j = min( i , j);
    for(i = j; i < n; i++)
        putchar(a[i]);
    for(i = 0; i < j; i++)
        putchar(a[i]);
}