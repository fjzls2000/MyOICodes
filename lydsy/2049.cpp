/**************************************************************
    Problem: 2049
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1652 ms
    Memory:1440 kb
****************************************************************/
 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10001
using namespace std;
int n,m,top,stack[N],fa[N],c[N][2];
bool rev[N];
bool isroot(int x){
    return (c[fa[x]][0]==x || c[fa[x]][1]==x);
}
void pushdown(int x){
    int ls=c[x][0],rs=c[x][1];
    swap(c[x][0],c[x][1]);
    if(ls) rev[ls]^=1;
    if(rs) rev[rs]^=1;
    rev[x]^=1;
}
void rotate(int x){
    int y=fa[x],z=fa[y],p,q;
    if(c[y][0]==x) p=0; else p=1;
    q=p^1;
    if(isroot(y)){
        if(c[z][0]==y) c[z][0]=x; else c[z][1]=x;
    }
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
    c[y][p]=c[x][q];c[x][q]=y;
}
void splay(int x){
    int p,y,z,top=0;
    for(p=x;isroot(p);p=fa[p]) stack[++top]=p;
    stack[++top]=p;
    for(;top;top--) if(rev[stack[top]]) pushdown(stack[top]);
    while(isroot(x)){
        y=fa[x];z=fa[y];
        if(isroot(y)){
            if((c[y][0]==x) ^ (c[z][0]==y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
}
void Access(int x){
    int V=0;
    while(x!=0){
        splay(x);
        c[x][1]=V;
        V=x;
        x=fa[x];
    }
}
void link(int x,int y){
    Access(x);splay(x);
    rev[x]^=1;
    fa[x]=y;
}
void cut(int x,int y){
    Access(x);splay(y);
    if(fa[y]==x)
        fa[y]=0;
    else {
        Access(y);splay(x);fa[x]=0;
    }
}
bool check(int x,int y){//判断x,y是否连通 
    Access(y);
    int V=0,t=x;
    bool OK=0;
    while(t!=0){
        if(t==y) OK=1;
        splay(t);
        c[t][1]=V;
        V=t;t=fa[t];
    }
    if(OK) return 1;
    splay(y);
    if(fa[y]!=0) return 1;
    else return 0; 
}
bool check2(int x , int y) {
    Access(x);
    splay(x);
    while(c[x][0]) x = c[x][0];
    Access(y);
    splay(y);
    while(c[y][0]) y = c[y][0];
    return x == y;
}
void solve(){
    int i,a,b;
    char s[10];    
    scanf("%d%d",&n,&m); 
    for(i=1;i<=m;i++){
        scanf("%s%d%d",s,&a,&b);
        if (s[0]=='C') link(a,b);
        if (s[0]=='D') cut(a,b);
        if (s[0]=='Q')
            if(check2(a,b)) printf("Yes\n");
            else printf("No\n");
    }
}
int main(){
    solve();
//    system("pause");
    return 0;
}