/**************************************************************
    Problem: 1876
    User: ZLSer_2015
    Language: Python
    Result: Accepted
    Time:2716 ms
    Memory:6416 kb
****************************************************************/
 
a,b=input(),input()
c=a%b
while c!=0L:
    a=b
    b=c
    c=a%b
print b