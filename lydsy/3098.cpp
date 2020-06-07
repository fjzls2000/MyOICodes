/**************************************************************
    Problem: 3098
    User: ZLSer_2015
    Language: C++
    Result: Accepted
    Time:8 ms
    Memory:1288 kb
****************************************************************/
 
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
using namespace std;
#define Maxn 100000
int n=Maxn,l=20;
int main() {
      cout<<n<<' '<<l<<endl;
      for(int i=1;i<=n;i++) cout<<char(rand()%26+'a');
      cout<<endl;
      return 0;
}
﻿