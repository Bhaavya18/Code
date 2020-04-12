#include<iostream>
using namespace std;
int main(int arg,char** argv)
{int n,r;
cout<<"enter no ";
cin>>n;
int nst=1;
int nsp=n-1;

for(r=1;r<=n;r++)
{ 
    for(int csp=1;csp<=nsp;csp++)
    {
        cout<<" ";
    }
    for(int cst=1;cst<=2*nst -1;cst++)
{cout<<"*";
}
nst++;
nsp--;
cout<<endl;

}

}