/**************************************************************
    Problem: 1012
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:1172 ms
    Memory:10180 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
#define INF 214748364
using std::min; using std::max;
const int Maxn = 200001;
int tree[800010] , ll[800010] , rr[800010];
int t = 0 , tcnt = 0;
long long mod;
  
void build(int x , int l , int r) {
    ll[x] = l; rr[x] = r;
    if( l == r ) return;
    int mid = (l + r)>>1;
    build(x<<1 , l , mid);
    build(x<<1|1 , mid+1 , r);
}
  
void update(int x , int tmp) {
    if(ll[x] > tcnt || rr[x] < tcnt) return;
    if(ll[x] == rr[x] && ll[x] == tcnt) tree[x] = tmp;
    else {
        update(x<<1 , tmp);
        update(x<<1|1 , tmp);
        tree[x] = max( tree[x<<1] , tree[x<<1|1] );
    }
}
  
int ans;
  
void query(int x , int l , int r) {
    l = max(l,ll[x]); r = min(r,rr[x]);
    if(r < l) return ;
    if(l == ll[x] && r == rr[x]) {
        if(tree[x] > ans) ans = tree[x];
    }
    else query(x<<1 , l , r) , query(x<<1|1 , l , r);
}
  
int main() {
    build(1,1,Maxn-1);
    int n , tmp , ch;
    scanf("%d%lld",&n,&mod);
    while(n--) {
        while(ch=getchar() , ch!='Q' && ch!='A');
        scanf("%d",&tmp);
        if(ch == 'Q') {
            ans = 0;
            query(1,tcnt-tmp+1,tcnt);
            printf("%d\n",ans % mod);
            t = ans;
        }
        else {
            tcnt++;
            tmp = ((long long)tmp + t) % mod;
            update(1,tmp);
        }
    }
}