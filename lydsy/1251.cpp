/**************************************************************
    Problem: 1251
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:9000 ms
    Memory:3636 kb
****************************************************************/
 
#include <stdio.h>
const int Maxn = 100010;
int num[Maxn] , tmax[Maxn] , fa[Maxn] , size[Maxn] , lazy[Maxn];
int c[Maxn][2]; // 0 左 1 右 
  
bool rev[Maxn];
  
int root , n;
  
void update(int x) {
    int tl = c[x][0] , tr = c[x][1];
      
    tmax[x] = num[x];
    if(tmax[tl] > tmax[x]) tmax[x] = tmax[tl];
    if(tmax[tr] > tmax[x]) tmax[x] = tmax[tr];
      
    size[x] = size[tl] + size[tr] + 1;
}
  
void downpush(int x) {
    int tl = c[x][0] , tr = c[x][1];
      
    if(rev[x]) {
        if(tl) rev[tl]^=1;
        if(tr) rev[tr]^=1;
        c[x][0] = tr; c[x][1] = tl;
        rev[x] ^= 1;
    }
      
    if(lazy[x]) {
        if(tl) {
            lazy[tl] += lazy[x];
            num[tl]  += lazy[x];
            tmax[tl] += lazy[x];
        }
        if(tr) {
            lazy[tr] += lazy[x];
            num[tr]  += lazy[x];
            tmax[tr] += lazy[x];
        }
        lazy[x] = 0;
    }
}
//===================================
void rotate(int &root,int x){ // 旋转 
    int y=fa[x],z=fa[y],p,q;
    if(c[y][0]==x) p=0; else p=1;
    q=p^1;
    if(y==root) root=x;
    else{
        if(c[z][0]==y) c[z][0]=x;
        else c[z][1]=x;
    }
    fa[x]=z;fa[y]=x;fa[c[x][q]]=y;
    c[y][p]=c[x][q];c[x][q]=y;
    update(y);update(x);
}
void splay(int &root,int x){
    int y,z;
    while(x!=root){
        y=fa[x];z=fa[y];
        if(y!=root){
            if((c[z][0]==y) ^ (c[y][0]==x)) rotate(root,x);
            else rotate(root,y);
        }
        rotate(root,x);
    }
}
//=========================================================
int find(int x , int k){
    downpush(x);
    int y=c[x][0];
    if(size[y]+1==k) return x;
    if(size[y]>=k) return find(c[x][0],k);
    else return find(c[x][1],k-size[y]-1);
}
  
void build(int last,int l,int r){
    if(l>r) return;
    int mid = (l+r) >> 1; 
      
    fa[mid] = last ; size[mid]=1;
      
    if(mid<last) c[last][0]=mid;
    else c[last][1]=mid;
      
    build(mid,l,mid-1);
    build(mid,mid+1,r);
      
    update(mid);
}
  
void add(int l , int r , int wi) {
    int x=find(root,l);
    splay(root,x);
    x=find(root,r+2);
    splay(c[root][1],x);
    //root = l , root右子树为r+2,那么r+2的左子树为 l < 子树 < r+2，即我们所要的。 
    x=c[c[root][1]][0];
    if (x) {
        lazy[x] += wi;
        num[x]  += wi;
        tmax[x] += wi;
    }
}
  
void reverse(int l , int r) {
    int x = find(root , l);
    splay(root,x);
    x = find(root,r+2);
    splay(c[root][1] , x);
    x = c[ c[root][1] ] [0];
    if(x) rev[x]^=1;
}
  
int getmax(int l , int r) {
    int x = find(root , l);
    splay(root , x);
    x = find(root , r+2);
    splay(c[root][1] , x);
    return tmax[ c[ c[root][1] ] [0] ];
} 
  
int main() {
    int t , k , l , r , tmp;
    num[0] = tmax[0] = -214748364;
    scanf("%d%d",&n,&t);
      
    n+=2;
    root = n>>1;
    build(0,1,n);
    /*Solve*/
    while(t--) {
        scanf("%d%d%d",&k,&l,&r);
        if ( k == 1 ) scanf("%d",&tmp) , add(l,r,tmp);
        if ( k == 2 ) reverse(l,r);
        if ( k == 3 ) printf("%d\n",getmax(l,r));
    }
}