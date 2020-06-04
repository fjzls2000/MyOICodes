/*
首先预处理ij位置放c对答案的贡献
然后预处理原图每个点对答案的贡献并且前缀和
然后我们对每个颜色前缀和
然后每张图就是 原图总答案-原图前缀和中一个矩形+颜色前缀和中一个矩形
最后取个最小的
我懒的搞longlong什么的了，应该能过？但是空间400+mb有点恐怖，很多步其实可以放在一个for里面完成。懒的改了还得写下一题QAQ
*/
#include <stdio.h>
inline int F() { register int aa , bb , ch;
    while(ch = getchar() , (ch<'0'||ch>'9') && ch != '-'); ch == '-' ? aa=bb=0 : (aa=ch-'0',bb=1);
    while(ch = getchar() , ch>='0'&&ch<='9') aa = aa*10 + ch-'0'; return bb ? aa : -aa;
}
const int Maxn = 1005;
const int Maxk = 300005;
struct Q { int x1 , y1 , x2 , y2 , f; } q[Maxk];
int n , m , k , col[26][Maxn][Maxn] , ans[26][Maxn][Maxn] , s[2][26];
long long p1[Maxn][Maxn] , p2[26][Maxn][Maxn];
char a[Maxn][Maxn] , ch;
int main() {
    n = F() , m = F() , k = F();
    for(int i=1; i<=n; ++i) scanf("%s",a[i]+1);
    //读入原图
    for(int i=1; i<=k; ++i) {
        q[i].x1 = F() , q[i].y1 = F() , q[i].x2 = F() , q[i].y2 = F();
        while(ch = getchar() , ch<'a'||ch>'z'); int f = ch - 'a'; q[i].f = f;
        int x1 = q[i].x1 , y1 = q[i].y1 , x2 = q[i].x2+1 , y2 = q[i].y2+1;
        ++col[f][x1][y1]; ++col[f][x2][y2];
        --col[f][x1][y2]; --col[f][x2][y1];
    }
    for(int f=0; f<26; ++f) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                col[f][i][j] += col[f][i-1][j] + col[f][i][j-1] - col[f][i-1][j-1];
            }
        }
    }
    //打上标记，前缀和后 col[f][i][j] 便是ij这个位置 f 颜色的个数。o
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            int sum = 0 , cnt = 0;
            for(int f=0; f<26; ++f) {
                sum += cnt;
                cnt += col[f][i][j];
            }
            col[a[i][j]-'a'][i][j] += k-cnt;
            sum += ('z'-a[i][j]) * (k-cnt); cnt = 0;
            for(int f=25; f>=0; --f) {
                ans[f][i][j] = sum;
                cnt += col[f][i][j];
                sum += cnt; sum -= k-cnt;
            }
        }
    //ans[f][i][j]表示ij这个位置放f对答案的贡献
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j) {
            p1[i][j] = p1[i-1][j] + p1[i][j-1] - p1[i-1][j-1] + ans[a[i][j]-'a'][i][j];
        }
    //得到 原图对答案的贡献
    for(int f=0; f<26; ++f) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                p2[f][i][j] = p2[f][i-1][j] + p2[f][i][j-1] - p2[f][i-1][j-1] + ans[f][i][j];
            }
        }
    }
    //得到 各个颜色对答案的贡献
    long long mn = 1e16;
    for(int i=1; i<=k; ++i) {
        int x1 = q[i].x1-1 , x2 = q[i].x2 , y1 = q[i].y1-1 , y2 = q[i].y2 , f = q[i].f;
        long long tmp = (p1[n][m] - p1[x2][y2] + p1[x1][y2] + p1[x2][y1] - p1[x1][y1]) + (p2[f][x2][y2] - p2[f][x1][y2] - p2[f][x2][y1] + p2[f][x1][y1]);
        if(tmp < mn) mn = tmp;
    }printf("%lld\n",mn);
    //统计k张图中每张图的答案
}