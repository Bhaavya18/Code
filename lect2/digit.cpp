#include<iostream>
using namespace std;
int main(int arg, char** argv)
{int n;
int p=0;
cout<<"enter no";
cin>>n;
if(n/10==0)
{cout<<"1 digit";}
else
{while(n!=0)
{n=n/10;
p++; }
cout<<p;
return 0;
}

}