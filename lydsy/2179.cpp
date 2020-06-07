/**************************************************************
    Problem: 2179
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:2772 ms
    Memory:6056 kb
****************************************************************/
 
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <complex>
const int Maxn = 131072;
typedef std::complex<double> E;
char ch[Maxn];
E a[Maxn] , b[Maxn];
int R[Maxn] , c[Maxn] , n , m , L;
void fft(E *a , int f) {
    for(int i=0; i<n; i++) if(R[i] < i) swap(a[R[i]] , a[i]);
    for(int i=1; i<n; i<<=1) {
        E Wn(cos(acos(-1)/i),f*sin(acos(-1)/i));
        for(int j=0; j<n; j+=(i<<1)) {
            E W(1,0);
            for(int k=0; k<i; k++) {
                E x = a[j+k] , y = W*a[j+k+i];
                a[j+k]=x+y;
                a[j+k+i]=x-y;
                W*=Wn;
            }
        }
    }if(f==-1) for(int i=0;i<n;i++) a[i]/=n;
}
int main() {
    scanf("%d",&n);n--;
    scanf("%s",ch);
    for(int i=0; i<=n; i++) a[i] = ch[n-i] - '0';
    scanf("%s",ch);
    for(int i=0; i<=n; i++) b[i] = ch[n-i] - '0';
    m = n*2 ; for(n=1; n <= m; n<<=1) L++;
    for(int i=0; i<=n; i++) R[i] = (R[i>>1]>>1) | ((i&1)<<(L-1));
    fft(a,1);fft(b,1);
    for(int i=0; i<=n; i++) a[i] *= b[i];
    fft(a,-1);
    for(int i=0; i<=m; i++) c[i] = (int)(a[i].real()+0.1);
    for(int i=0; i<=m; i++)
        if(c[i] >= 10) {
            c[i+1]+=c[i]/10;
            c[i]%=10;
            if(i == m) m++;
        }
    for(int i=m; i>=0; i--) printf("%d",c[i]);
}