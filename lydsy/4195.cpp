/**************************************************************
    Problem: 4195
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1068 ms
    Memory:4384 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define For(i,a,b) for(register int i=a,__u=b; i<=__u; i++)
const int MAXBUF=1<<18;int aa,bb;char ch,B[MAXBUF],*S=B,*T=B;
#define getc (S==T&&(T=(S=B)+fread(B,1,MAXBUF,stdin),S==T)?0:*S++)
namespace tools{
    inline int F() {
        while(ch=getc,(ch<'0'||ch>'9')&&ch!='-');ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
        while(ch=getc,ch>='0'&&ch<='9')aa=aa*10+ch-'0';return bb?aa:(-aa);
    }
}using namespace tools;
#define Maximum 200010
int Table[Maximum]={},f[Maximum]={},ask[Maximum][2]={};bool used[Maximum]={};
inline int find(int x) {
    if(f[x]==x) return x;
    else f[x]=find(f[x]);
    return f[x];
}
inline void bing(register int a,register int b) {
    if (find(a)!=find(b)) f[f[a]]=f[b];
}
inline int sunique(register int n) {
    register int now=0;
    For(i,1,n) if(Table[now]!=Table[i]) Table[++now]=Table[i],f[now]=now;
    return now;
}
#define whatnum(i) std::lower_bound(Table+1,Table+len+1,i)-Table
int main () {
    int t=F();
    while(t--) {
        int m1,m2,n=F(),len,m=0;
        For(i,1,n) Table[2*i-1]=ask[i][0]=F(),Table[2*i]=ask[i][1]=F(),used[i]=F();
        std::sort(Table+1,Table+n+n+1);len=sunique(n*2);
        For(i,1,n) {
            if(!used[i]) ask[++m][0]=ask[i][0],ask[m][1]=ask[i][1];
            else {
                m1=whatnum(ask[i][0]);m2=whatnum(ask[i][1]);
                bing(m1,m2);
            }
        }For(i,1,m) {
            if(find(whatnum(ask[i][0]))==find(whatnum(ask[i][1]))) {
                puts("NO");goto THEEND;
            }
        }puts("YES");THEEND:;
    }
}