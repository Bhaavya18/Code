#include<iostream>
using namespace std;
void trispace(int n)
{
int r;
int nst=1;
int nsp=1;
for(r=1;r<=n;r++)
{    if(r<=2)
   { for(int cst=1;cst<=nst;cst++)
    {
        cout<<"*";
    }
   }
    if(r>=3 && r!=n)
    {
        cout<<"*";
        for(int csp=1;csp<=nsp;csp++)
        {
            cout<<" ";
        }
        cout<<"*";
        nsp++;
    }
    if(r==n)
    {
        for(int cst=1;cst<=nst;cst++)
        {
            cout<<"*";
        }
    }
     cout<<endl;
    nst++;
    

}
}
int  main(int arg,char** argv)
{
    int n;
    cout<<" enter n";
    cin>>n;
    trispace(n);
    return 0;
}





