/**************************************************************
    Problem: 3403
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:84 ms
    Memory:1212 kb
****************************************************************/
 
#include <stdio.h>
 
const int Maxn = 100010;
int q[Maxn] , h , t , n , tmp , ch , cnt = 0;
 
void insh(int x) {
    if(--h < 0) h += Maxn;
    q[h] = x;
}
 
void inst(int x) {
    if(++t >= Maxn) t -= Maxn;
    q[t] = x;
}
 
void popt(int x) {
    t -= x;
    if(t < 0) t += Maxn;
}
 
void poph(int x) {
    h += x;
    if(h >= Maxn) h -= Maxn;
}
 
int main() {
    h = 2 , t = 1 ;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) {
        while(ch = getchar() , ch != 'A' && ch != 'D');
        if(ch == 'A') {
            while(ch = getchar() , ch != 'L' && ch != 'R');
            if(ch == 'L') insh(++cnt);
            else inst(++cnt);
        }
        else {
            while(ch = getchar() , ch != 'L' && ch != 'R');
            scanf("%d",&tmp);
            if(ch == 'L') poph(tmp);
            else popt(tmp);
        }
    }
    while(h!=t) {
        printf("%d\n",q[h]);
        poph(1);
    }printf("%d",q[h]);
}