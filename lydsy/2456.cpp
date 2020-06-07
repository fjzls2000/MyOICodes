/**************************************************************
    Problem: 2456
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:384 ms
    Memory:820 kb
****************************************************************/
 
#include<cstdio>
int n,t,x,tot;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&x);
        if(x==t)tot++;
        else if(!tot)
        {t=x;tot=1;}
        else tot--;
    }
    printf("%d",t);
}