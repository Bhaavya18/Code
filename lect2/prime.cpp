#include<iostream>
using namespace std;
int isprime(int n)
{int i;
int flag=0;
for(i=2;i*i<=n;i++)
{ if(n/i!=0)
{flag =1;
break;}
}
return flag;
}
int main(int arg,char** argv)
{ int num;
cout<<"enter number";
cin>>num;
int p=isprime(num);
if(p==1)
{cout<<"prime no";}
else
{cout<<"not prime";}
return 0;
}
