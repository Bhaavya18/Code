#include<iostream>
using namespace std;
int main(int arg,char ** argv)
{int n,r;
cout<<"enter no of rows";
cin>>n;
int nst=1;
for(r=1;r<=n;r++)
{ for( int cst=1;cst<=nst;cst++)
{cout<<"*";}
cout<<endl;
nst++;
}

}