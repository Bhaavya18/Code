#include<iostream>
using namespace std;
int main(int argv, char** args)
{int p,n,t,i;
cout<<"enter number for table"<<endl;
cin>>p;
cout<<"upto which number table has to be printed"<<endl;
cin>>n;
for(i=1;i<=n;i++)
{t=p*i;
cout<<t<<endl;}
return 0;

}