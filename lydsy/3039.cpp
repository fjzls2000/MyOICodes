/**************************************************************
    Problem: 3039
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:276 ms
    Memory:4728 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
using std::min;using std::max;
const int Maxn = 1001;
int n , m , top , ch , ans = 0 , len = 0;
int map[Maxn][Maxn] , l[Maxn] , s[Maxn];
 
int Getans(int a[]) {
    l[top = 0] = s[top] = 0;
    for(int i=1; i<=m; i++) {
        len = 0;
        while(top && s[top] > a[i]) {
            len += l[top];
            ans = max( ans , len * s[top]);
            top--;
        }
        s[++top] = a[i];
        l[top] = len+1;
    }
    len = 0;
    while(top) {
        len += l[top];
        ans = max(ans , len * s[top]);
        top--;
    }return ans;
}
 
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            while(ch=getchar() , ch!='R' && ch!='F');
            if(ch == 'F') map[i][j] = map[i-1][j]+1;
            else map[i][j] = 0;
        }Getans(map[i]);
    }return !printf("%d",3*ans);
}