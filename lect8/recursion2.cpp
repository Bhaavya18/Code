#include<iostream>
using namespace std;
void numdecr(int n)
{
    if(n==0)
    {
        cout<<"base"<<n<<endl;
        return ;
    }
    cout<<n<<endl;
    numdecr(n-1);
    
}
void numincre(int n)
{
    if(n==0)
    {
        cout<<"base"<<n<<endl;
        return;
    }
    numincre(n-1);
    cout<<n<<endl;
}
void printoddeven(int n)
{ if(n==0)
return;
if(n%2==0)
cout<<n<<" ";
printoddeven(n-1);
if(n%2!=0)
cout<<n<<" ";
}
int main(int arg,char** argv)
{
    int n;
    cin>>n;
   // numincre(n);
   // numdecr(n);
   printoddeven(n);
}