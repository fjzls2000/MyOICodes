/**************************************************************
    Problem: 1901
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:496 ms
    Memory:26920 kb
****************************************************************/
 
#include <stdio.h>
#include <algorithm>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch!='-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
int n , m , tot , top , sz;
int v[10001] , num[20001];
int flag[10001] , A[10001] , B[10001] , K[10001] , root[10001];
int sum[2200001] , ls[2200001] , rs[2200001];
int L[30] , R[30] , a , b; 
#define lowbit(a) ((a) & -(a))
int find(int x) {
    int l = 1 , r = tot , mid , ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(num[mid] <= x) ans = mid , l = mid + 1;
        else r = mid-1;
    }return ans;
}
void update(int lst , int l , int r , int &rt , int w , int x) {
    rt = ++sz;
    sum[rt] = sum[lst]+x; ls[rt] = ls[lst]; rs[rt] = rs[lst];
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(w <= mid) update(ls[lst] , l , mid , ls[rt] , w , x);
    else update(rs[lst] , mid+1 , r , rs[rt] , w , x);
}
int query(int l , int r , int k) {
    if(l == r) return l;
    int suml = 0 , sumr = 0 , mid = (l + r) >> 1;
    for(int i=1; i<=a; ++i) suml += sum[ls[L[i]]];
    for(int i=1; i<=b; ++i) sumr += sum[ls[R[i]]];
    if(sumr - suml >= k) {
        for(int i=1; i<=a; ++i) L[i] = ls[L[i]];
        for(int i=1; i<=b; ++i) R[i] = ls[R[i]];
        return query(l,mid,k);
    }
    else {
        for(int i=1; i<=a; ++i) L[i] = rs[L[i]];
        for(int i=1; i<=b; ++i) R[i] = rs[R[i]];
        return query(mid+1,r,k-(sumr-suml));
    }
}
char s[3];
int main() {
    n = F() , m = F();
    for(int i=1; i<=n; ++i) {
        v[i] = F();
        num[++top] = v[i];
    }
    for(int i=1; i<=m; ++i) {
        scanf("%s",s);
        A[i] = F() , B[i] = F();
        if(s[0] == 'Q') K[i] = F() , flag[i] = 1;
        else num[++top] = B[i];
    }
    std::sort(num+1,num+top+1);
    tot = 1;
    for(int i=2; i<=top; ++i)
        if(num[i]!=num[i-1])
            num[++tot] = num[i];
    for(int i=1; i<=n; ++i) {
        int t = find(v[i]);
        for(int j=i; j<=n; j+=lowbit(j))
            update(root[j],1,tot,root[j],t,1);
    }
    for(int i=1; i<=m; ++i)
        if(flag[i]) {
            a = 0; b = 0; --A[i];
            for(int j=A[i]; j; j-=lowbit(j))
                L[++a] = root[j];
            for(int j=B[i]; j; j-=lowbit(j))
                R[++b] = root[j];
            printf("%d\n",num[query(1,tot,K[i])]);
        }
        else {
            int t = find(v[A[i]]);
            for(int j=A[i]; j<=n; j+=lowbit(j))
                update(root[j],1,tot,root[j],t,-1);
            v[A[i]] = B[i];
            t = find(B[i]);
            for(int j=A[i]; j<=n; j+=lowbit(j))
                update(root[j],1,tot,root[j],t,1);
        }
}