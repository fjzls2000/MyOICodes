/**************************************************************
    Problem: 1010
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:128 ms
    Memory:6072 kb
****************************************************************/
 
#include <stdio.h>
typedef long long ll;
  
const int Maxn = 50001;
int n , L , l , r , q[Maxn] , a[Maxn];
ll f[Maxn] , s[Maxn];
  
namespace tools{
    const int MAXBUF = 1<<22; char B[MAXBUF] , *S = B , *T = B;
    #define getc (S==T&&(T = (S = B) +fread(B,1,MAXBUF,stdin),S==T) ? EOF : *S++)
      
    inline int F() {register int aa,bb,ch;
        while(ch=getc,(ch<'0'||ch>'9') && ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
        while(ch=getc,ch>='0'&&ch<='9')aa=aa*10+ch-'0';return bb?aa:-aa;
    }
      
    double slope(int y , int x) {
        return (f[x]-f[y]+s[x]*s[x]-s[y]*s[y]+2*s[x]*L-2*s[y]*L) / (2.0*(s[x]-s[y]));
    }
}using namespace tools;
  
void dp(){
    l = r = 1;q[1] = 0;
    for(int i=1; i<=n; i++) {
        while(l < r && slope(q[l],q[l+1])<=s[i]) l++;
        int head = q[l] ;
        f[i] = f[head] + (s[i]-s[head]-L) * (s[i]-s[head]-L);
        while(l < r && slope( q[r] , i ) < slope(q[r-1],q[r])) r--;
        q[++r] = i;
    }
}
  
int main() {
    n = F(); L = F(); L++; 
    for(int i=1; i<=n; i++) ( a[i] = F() ) , s[i] = s[i-1] + a[i] + 1;
    dp();
    printf("%lld",f[n]);
}