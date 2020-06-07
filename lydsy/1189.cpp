/**************************************************************
    Problem: 1189
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:180 ms
    Memory:9312 kb
****************************************************************/
 
/*#include <stdio.h>
#include <memory.h>
const int inf = 233333333; const int Maxn = 100010; const int Maxm = 500010;
const int ss[2][4] = {1,0,-1,0,0,1,0,-1};
inline int min(int a , int b) { return a > b ? b : a ; }
 
int n , m , map[101][101] , dcnt = 0 , ncnt = 0 , q[Maxm] , qi[Maxm] , qj[Maxm] , t , w , S , T , ans , tot = 0 , dis[101][101][101] , mk[101][101];
int h[Maxn] , to[Maxm] , next[Maxm] , g[Maxm] , flow[Maxm] , ecnt = 1;
inline void ins(int a , int b , int c) { to[++ecnt] = b; next[ecnt] = g[a]; g[a] = ecnt; flow[ecnt] = c; to[++ecnt] = a; next[ecnt] = g[b]; g[b] = ecnt; flow[ecnt] = 0;}
 
void BFS(int i , int j) {
    int now = map[i][j] , nowi , nowj;
    dis[i][j][now] = 0;
    qi[t = w = 1] = i; qj[1] = j;
    while(t<=w) {
        for(int k=0; k<4; ++k) {
            nowi = qi[t] + ss[0][k]; nowj = qj[t] + ss[1][k];
            if (nowi<1||nowj<1||nowi>n||nowj>m||map[nowi][nowj] != 0) continue;
            if (dis[nowi][nowj][now] == inf) {
                dis[nowi][nowj][now] = dis[qi[t]][qj[t]][now]+1;
                qi[++w] = nowi; qj[w] = nowj;
            }
        }++t;
    }dis[i][j][now] = inf;
}
 
void Init() {
    int ch;
    scanf("%d%d",&n,&m);
    S = 0 ; T = n*m*2+1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            mk[i][j] = ++ncnt;
            while(ch = getchar() , ch != '.' && ch != 'X' && ch != 'D');
            if( ch == '.' ) map[i][j] = 0 , ++tot;
            if( ch == 'X' ) map[i][j] = -1;
            if( ch == 'D' ) map[i][j] = ++dcnt;
        }
//  for(int i=1; i<=n; ++i) {for(int j=1; j<=m; ++j) printf("%d ",map[i][j]); puts("");}
    for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) for(int k=1; k<=dcnt; ++k) dis[i][j][k] = inf;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(map[i][j] > 0) BFS(i,j);
}
 
bool bfs() {
    memset(h,-1,sizeof(h));
    h[ q[t = w = 1] = S ] = 0;
    while(t <= w) {
        int now = q[t++];
        for(int i=g[now]; i; i=next[i])
            if(h[to[i]] == -1 && flow[i]) h[to[i]] = h[now] + 1 , q[++w] = to[i];
    }return h[T] != -1;
}
 
int dfs(int x , int lim) {
    if(x == T) return lim;
    int w , used;
    for(int i=g[x]; i; i=next[i])
        if(flow[i] && h[to[i]] == h[x] + 1) {
            w = lim - used;
            w = dfs(to[i] , min(w , flow[i]));
            flow[i] -= w;
            flow[i^1] += w;
            used += w;
            if(used == lim) return used;
        }
    if(!used) h[x] = -1;
    return used;
}
 
void dinic() {while(bfs()) ans+=dfs(S,inf);}
 
void build(int x) {
    memset(g,0,sizeof(g)); ecnt = 1;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            if(map[i][j] == 0) ins(S,mk[i][j],1);
    for(int i=1; i<=dcnt; ++i) ins(n*m+i,T,x);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            for(int k=1; k<=dcnt; ++k)
                if(dis[i][j][k] <= x) ins(mk[i][j] , n*m+k , 1);
}
 
bool check(int x) {
    build(x);
    ans = 0;
    dinic();
    return ans == tot;
}
 
int main() {
    Init();
    int l = 0 , r = 400 , mid , mn = -1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid)) mn = mid , r = mid-1;
        else l = mid + 1;
    }if( mn = -1 ) puts("impossible"); else printf("%d",mn);
}*//* 
#include<iostream>
#include<cstdio>
#include<cstring>
#define S 0
#define T 1000
#define inf 0x7fffffff
using namespace std;
int n,m,door=1,cnt,ans,tot,mn=-1;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
int mp[21][21],head[1001],h[1001],q[1001];
int dis[401][21][21];
struct data{int x,y,s;}d[401];
struct data2{int to,next,v;}e[1000001];
bool bfs()
{
    int t=0,w=1,i,now;
    memset(h,-1,sizeof(h));
    h[S]=0;q[0]=S;
    while(t<w)
    {
        now=q[t];t++;
        i=head[now];
        while(i)
        {
            if(h[e[i].to]==-1&&e[i].v){h[e[i].to]=h[now]+1;q[w++]=e[i].to;}
            i=e[i].next;
        }
    }
    if(h[T]==-1)return 0;
    return 1;
}
int dfs(int x,int f)
{
    if(x==T)return f;
    int i=head[x];
    int w,used=0;
    while(i)
    {
        if(e[i].v&&h[e[i].to]==h[x]+1)
        {
            w=f-used;
            w=dfs(e[i].to,min(w,e[i].v));
            e[i].v-=w;
            e[i^1].v+=w;
            used+=w;
            if(used==f)return f;                      
        }
        i=e[i].next;
    }
    if(!used)h[x]=-1;
    return used;
}
void dinic(){while(bfs())ans+=dfs(0,inf);}
void ins(int u,int v,int w)
{e[++cnt].to=v;e[cnt].next=head[u];e[cnt].v=w;head[u]=cnt;}
void insert(int u,int v,int w)
{ins(u,v,w);ins(v,u,0);} 
void build(int x)
{
    memset(head,0,sizeof(head));
    cnt=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]==1)insert(S,(i-1)*m+j,1);
    for(int i=2;i<=door;i++)insert(n*m+i,T,x);
    for(int i=2;i<=door;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                if(dis[i][j][k]<=x)insert((j-1)*m+k,n*m+i,x);
}
void search(int k,int x,int y) 
{
    int t=0,w=1,nowx,nowy;
    d[0].x=x;d[0].y=y;
    while(t<w)
    {
        for(int i=0;i<4;i++)
        {   
            nowx=d[t].x+xx[i],nowy=d[t].y+yy[i];
            if(nowx<1||nowy<1||nowx>n||nowy>m||mp[nowx][nowy]!=1)continue;
            if(dis[k][nowx][nowy]==inf)
            {
                dis[k][nowx][nowy]=d[w].s=d[t].s+1;
                d[w].x=nowx;d[w].y=nowy;
                w++; 
            }
        }
        t++;
    }
}
bool judge(int x)
{ 
    build(x);
    ans=0;
    dinic();
    if(ans==tot)return 1;
    return 0; 
}
int main()
{
    scanf("%d%d",&n,&m);
    char ch[21];
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch);
        for(int j=1;j<=m;j++)
        {
            if(ch[j-1]=='.'){mp[i][j]=1;tot++;}
            else if(ch[j-1]=='D')mp[i][j]=++door; 
        }
    }
    for(int i=2;i<=door;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
                dis[i][j][k]=inf;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mp[i][j]>1)search(mp[i][j],i,j);
    int l=0,r=400;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid)){mn=mid;r=mid-1;}
        else l=mid+1;
    }
    if(mn==-1)printf("impossible");
    else printf("%d",mn);
    return 0;
}*/
#include <queue>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define P 25  
#define N 500  
#define M 300000  
#define R 500  
#define inf 0x3f3f3f3f  
using namespace std;  
const int dx[]={0,0,1,-1};  
const int dy[]={1,-1,0,0};  
struct KSD  
{  
    int v,len,next;  
    int flow;  
    void init(){len=flow;}  
}e[M];  
int head[50000],cnt;  
inline void add(int u,int v,int len)  
{  
    e[++cnt].v=v;  
    e[cnt].len=e[cnt].flow=len;  
    e[cnt].next=head[u];  
    head[u]=cnt;  
}  
inline void Add(int u,int v,int len){add(u,v,len),add(v,u,0);}  
int s,t,d[50000];  
queue<int>q;  
bool bfs()  
{  
    memset(d,0,sizeof d);  
    while(!q.empty())q.pop();  
   
    int i,u,v;  
    q.push(s),d[s]=1;  
    while(!q.empty())  
    {  
        u=q.front(),q.pop();  
        for(i=head[u];i;i=e[i].next)  
        {  
            if(!d[v=e[i].v]&&e[i].len)  
            {  
                d[v]=d[u]+1;  
                if(v==t)return 1;  
                q.push(v);  
            }  
        }  
    }  
    return 0;  
}  
int dinic(int x,int flow)  
{  
    if(x==t)return flow;  
    int remain=flow,i,v,k;  
    for(i=head[x];i&&remain;i=e[i].next)  
    {  
        if(e[i].len&&d[v=e[i].v]==d[x]+1)  
        {  
            k=dinic(v,min(remain,e[i].len));  
            if(!k)d[v]=0;  
            e[i].len-=k,e[i^1].len+=k;  
            remain-=k;  
        }  
    }  
    return flow-remain;  
}  
   
int blank[N],blanks;  
int door[N],doors;  
int point[N][R+5],rec[N][R+5];  
bool is_door[N];  
void build(int mid)  
{  
    int i,j;  
    for(i=2;i<=cnt;i++)e[i].init();  
    for(i=1;i<=doors;i++)for(j=mid+1;j<=R;j++)e[rec[i][j]].len=0;  
    return ;  
}  
int n,m,id[P][P];  
int map[N][N];  
char src[P][P];  
void Build(int &l,int &r)  
{  
    int i,j,k;  
    int tx,ty;  
    scanf("%d%d",&n,&m);  
    for(i=1;i<=n;i++)scanf("%s",src[i]+1);  
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)  
    {  
        if(src[i][j]=='.')blank[++blanks]=id[i][j]=++cnt;  
        else if(src[i][j]=='D')  
        {  
            door[++doors]=id[i][j]=++cnt;  
            is_door[cnt]=true;  
        }  
    }     
    memset(map,0x3f,sizeof map);  
    for(i=1;i<=cnt;i++)map[i][i]=0;  
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(id[i][j])  
        for(k=0;k<4;k++)if(id[tx=i+dx[k]][ty=j+dy[k]])  
            map[id[i][j]][id[tx][ty]]=1;  
    for(k=1;k<=cnt;k++)  
    {  
        if(is_door[k])continue;  
        for(i=1;i<=cnt;i++)for(j=1;j<=cnt;j++)map[i][j]=min(map[i][j],map[i][k]+map[k][j]);  
    }  
    cnt=blanks;  
    for(i=1;i<=doors;i++)for(j=1;j<=R;j++)point[i][j]=++cnt;  
    s=0,t=cnt+1,cnt=1;  
    for(i=1;i<=blanks;i++)  
    {  
        Add(s,i,1); // 500  
        int res=inf;  
        for(j=1;j<=doors;j++)  
            res=min(res,map[blank[i]][door[j]]);  
        l=max(l,res);  
    }  
    for(i=1;i<=doors;i++)  
    {  
        int I=door[i],J;  
        for(j=1;j<=blanks;j++)if(map[I][J=blank[j]]<inf)  
            Add(j,point[i][map[I][J]],1);  
    }  
    for(i=1;i<=doors;i++)for(j=1;j<R;j++)Add(point[i][j],point[i][j+1],inf);  
   
    for(i=1;i<=doors;i++)for(j=1;j<=R;j++) // 80*500  
    {  
        Add(point[i][j],t,1);  
        rec[i][j]=cnt-1;  
    }  
    return ;  
}  
bool check(int mid)  
{  
    build(mid);  
    int maxflow=0;  
    while(bfs())maxflow+=dinic(s,inf);  
    if(maxflow==blanks)return 1;  
    return 0;  
}  
int main()  
{  
    int l=0,r=R,mid,ans=inf;  
    Build(l,r);  
    while(l<=r)  
    {  
        if(r-l<=3)  
        {  
            for(int i=l;i<=r;i++)if(check(i)){ans=i;break;}  
            break;  
        }  
        mid=l+r>>1;  
        if(check(mid))r=mid;  
        else l=mid+1;  
    }  
    if(ans==inf)puts("impossible");  
    else printf("%d\n",ans);  
    return 0;  
} 
/*
 
5 5
XXXXX
X...X
XX.XX
X..XX
XXDXX
 
*/