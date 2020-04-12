#include<iostream>
using namespace std;
int main(int arg, char** argv)
{ int n;
cout<<"enter no of rows";
cin>>n;
int nst=1;
int r;
int nsp=(2*n) -3;
for(r=1;r<=n;r++)
{ int p=1;
for(int cst=1;cst<=nst;cst++)
{
cout<<p;
p++;
}
for(int csp=1;csp<=nsp;csp++)
{
    cout<<" ";
}
for(int cst=r;cst>=1;cst--)
{
    if(cst==n)
    {continue;}
    cout<<cst;

}
cout<<endl;
nsp-=2;
nst++;


}


return 0;
}