#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
const int Maxn = 1000005;
int n , len , cnt[100] , ch; char s[Maxn];
string s1 , s2 , s3;
void Init() {
    while(ch = getchar() , ch < '0' || ch > '9'); ++cnt[ch-'0']; n = 1;
    while(ch = getchar() ,ch >= '0' && ch <= '9') ++cnt[ch-'0'] , ++n ;
    scanf("%s",s+1);
}
int bit(int x){
    int ans = 0;
    while(x) x/=10 , ++ans;
    return ans;
}
void getlen() {
    int len = n;
    while(bit(len) != n-len) --len;
    int tmp = n = len;
    while(tmp) --cnt[tmp%10] , tmp/=10;
    len = strlen(s+1);
    for(int i=1; i<=len; ++i) {
        --cnt[s[i]-'0']; --n;
    }
}
int main() {
    Init();
    getlen();
    if(n == 0) {
        printf("%s",s+1);
    } else if(s[1] == '0') {
        int flag;
        for(int i=1; i<=9; ++i) {
            if(cnt[i]) {
                flag = i; break;
            }
        }
        printf("%d",flag); --cnt[flag];
        while(cnt[0]--) printf("0"); printf("%s",s+1);
        for(int i=1; i<=9; ++i) while(cnt[i]--) printf("%d",i);
    }
    else {
        int flag = 0;
        for(int i=1; i<=9; ++i) {
            if(cnt[i]) {
                flag = i; break;
            }
        }
        if(!flag) {
            printf("%s",s+1); while(cnt[0]--) printf("0"); return 0;
        }
        else if(flag > s[1]-'0') {
            printf("%s",s+1);
            for(int i=0; i<=9; ++i) while(cnt[i]--) printf("%d",i);
        }
        else {
            s1 += s+1;
            for(int i=0; i<=9; ++i) {
                int tmp = cnt[i];
                while(tmp--) s1 += i+'0';
            }
            s2 += flag+'0'; s3 += flag+'0';
            --cnt[flag];
            for(int i=0; i<s[1]-'0'; ++i) {
                while(cnt[i]--) {
                    s2 += i+'0';
                    s3 += i+'0';
                }
            }
            s2 += s+1;
            while(cnt[s[1]-'0']--) {
                s2 += s[1];
                s3 += s[1];
            }
            s3 += s+1;
            for(int i=s[1]-'0'+1; i<10; ++i) {
                while(cnt[i]--) {
                    s2 += i+'0';
                    s3 += i+'0';
                }
            }
            if(s1 > s2) {
                if(s2 > s3) cout<<s3;
                else cout<<s2;
            }
            else {
                if(s1 > s3) cout<<s3;
                else cout<<s1;
            }
        }
    }
}