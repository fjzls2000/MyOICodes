/**************************************************************
    Problem: 1666
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:820 kb
****************************************************************/
 
#include<cstdio>
int n,ans;
int main()
{
    scanf("%d",&n);
    while(n^1)
    {
        if(n&1)n=n*3+1;
        else n>>=1;
        ans++;
    }
    printf("%d",ans);
    return 0;
}