/**************************************************************
    Problem: 1724
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:24 ms
    Memory:952 kb
****************************************************************/
 
#include <stdio.h>
#include <queue>
std::priority_queue<int> q;
int main() {
    int n , tmp; long long ans = 0;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&tmp) , q.push(-tmp);
    while(--n) {
        tmp = q.top();
        q.pop();
        tmp+=q.top();
        q.pop();
        ans+=tmp;
        q.push(tmp);
    }
    printf("%lld",-ans);
}