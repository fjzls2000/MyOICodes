/**************************************************************
    Problem: 3450
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:1100 kb
****************************************************************/
 
/* x 显然，x以后的得分与原来相同，所以对答案贡献为0
   o 这一位为o，那么对答案，因为我原来len的贡献算过了，所以贡献为(len+1)^2 - len^2 = 2len+1;
   ? 50% o --> len+0.5  50% x --> 0 所以 ans+=len+0.5;len=(len+1)/2.0;*/
#include <stdio.h>
double f , d ; int n; char s[300010];
int main() {
    f = d = 0;
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1; i<=n; i++)
        if(s[i] == 'x') d = 0;
        else if(s[i] == 'o') { f = f + d + d + 1; d+=1;}
        else { f = f+d+0.5;d = (d+1)/2.0;}
    printf("%.4lf",f);
}