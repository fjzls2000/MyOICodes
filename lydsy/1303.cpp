/**************************************************************
    Problem: 1303
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:28 ms
    Memory:3948 kb
****************************************************************/
 
#include <stdio.h>
//const int MAXBUF = 1<<22;char B[MAXBUF] , *S = B , *T = B;
//#define getch() (S == T && (T = (S = B) + fread(B,1,MAXBUF,stdin) , S == T ) ? EOF : *S ++)
#define getch() getchar()
int F() {register int aa , ch;
    while(ch = getch() , ch<'0'||ch>'9'); aa = ch - '0';
    while(ch = getch() ,ch>='0'&&ch<='9') aa = aa*10+ch-'0';
    return aa;
}
const int Maxn = 200010;
#define R register 
int a[Maxn] , l[Maxn] , r[Maxn] , tong[Maxn] , ans = 0;
int main() {
    int n = F() , k = F() , t;
    for(int i=1; i<=n; ++i) {
        a[i] = F();
        if(a[i] == k) t = i;
        a[i] = (a[i] == k ? 0 : (a[i] > k ? 1 : -1));
    }
    tong[100000] = 1;
    for(int i=t-1; i; --i)
        l[i] = l[i+1] + a[i] , ++tong[100000+l[i]];
    for(int i=t; i<=n; ++i)
        r[i] = r[i-1] + a[i] , ans += tong[100000-r[i]];
    printf("%d\n",ans);
}