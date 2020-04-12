#include<iostream>
using namespace std;
int calsetbit(int x)
{ int count=0;
    for(int i=0;i<32;i++)
    {
        int mask=1<<i;
        if((x& mask)!=0)
        count++;

    }
    return count;
}
int icalsetbit(int x)
{ int bits=0;
 int count=0;
while(x!=0 && bits<32) //if bits<32 condition is not used then for -1 loop will run infinite times 
    { if((x&1)!=0)
       {  count++; }
         x>>=1;
         bits++;
    }
    return count;
}
int calsetbit3(int n)
{
    int count;
    while(n!=0)
    {
       n=n&(n-1);
       count ++;
    }
    return count;
}
int main(int arg,char** argv)
{
    int x;
    cin>>x;
  // cout<<calsetbit(x);
 // cout<<icalsetbit(x);
  cout<<calsetbit3(x);
   return 0;
}