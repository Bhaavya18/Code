#include<iostream>
using namespace std;
int main(int arg,char** argv)
{int n,c;
int p=0;
cout<<"enter no";
cin>>n;
while(n!=0)
{c=n%10;
p=p*10 +c;
n=n/10;
}
cout<<p;
return 0;
}


