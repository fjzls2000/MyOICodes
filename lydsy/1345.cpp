/**************************************************************
    Problem: 1345
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1660 ms
    Memory:1196 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
using std::min ; using std::max;
const int Maxn = 100010;
int n , q[Maxn] , top = 0 , tmp;
long long ans = 0 ;
int main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&tmp);
        while(top && tmp >= q[top]) {
            if(top == 1) ans += tmp;
            else ans += min( q[top - 1] , tmp);
            top--;
        }q[++top] = tmp;
    }
    while(top>1) {
        ans+=q[top-1];
        top--;
    }printf("%lld",ans);
}