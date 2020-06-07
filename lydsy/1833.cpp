/**************************************************************
    Problem: 1833
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:4920 kb
****************************************************************/
 
#include <stdio.h>
typedef long long ll;
#define R register
  
const int MAXBUF = 1<<22; char B[MAXBUF] , *S = B , *T = B;
//#define getch() (S == T && (T = (S = B) + fread(B,1,MAXBUF,stdin) , S == T ) ? EOF : *S ++)
#define getch() getchar()
inline ll F() {
    R ll aa;R int bb,ch;
    while(ch=getch() , (ch<'0'||ch>'9') && ch!='-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch=getch() , ch>='0'&&ch<='9') aa=aa*10+ch-'0'; return bb ? aa : -aa;
}
  
ll a , b , p[16];
struct node { ll c[10]; } f[16][10] , ansa , ansb;
inline node operator + (node a , node b) { for(R int i=0; i<10; ++i) a.c[i] += b.c[i]; return a; }
inline void operator += (node&a , node b) { a = a + b;}
  
node calc(ll x) {
    node ans; R int i , j , len = 14 , head;
    for(i=1; i<10; ++i) ans.c[i] = 0; ans.c[0] = 1;
    if(!x) return ans;
      
    while(p[len-1] > x && len-1) --len;
    for(i=1; i<len; ++i) for(j=1; j<10; ++j) ans += f[i][j];
      
    head = x/p[len-1];
    for(i=1; i<head; ++i) ans += f[len][i];
    x%=p[len-1];
    ans.c[head] += x+1;
      
    for(i=len-1; i>0; --i) {
        head = x/p[i-1];
        for(j=0; j<head; ++j)
            ans+=f[i][j];
        x%=p[i-1];
        ans.c[head]+=x+1;
    }
      
    return ans;
}
  
int main() {
    R int i , j , k;
    for(p[0] = i = 1; i<=14; ++i) p[i] = p[i-1] * 10;
    for(i=0; i<10; ++i) f[1][i].c[i] = 1;
    for(i=2; i<=12; ++i) {
        for(j=0; j<10; ++j)
            for(k=0; k<10; ++k)
                f[i][k] += f[i-1][j];
        for(int j=0; j<10; ++j) f[i][j].c[j] += p[i-1];
    }
    a = F(); b = F();
    ansa = calc(a-1) , ansb = calc(b);
    for(i=0; i<9; ++i) printf("%lld ",ansb.c[i] - ansa.c[i]);
    printf("%lld", ansb.c[9] - ansa.c[9]);
    return 0;
}