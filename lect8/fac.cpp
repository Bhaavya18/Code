#include<iostream>
using namespace std;
int fact(int n)
{
    if(n<=1)
    {
        return 1;
    }
    int res=fact(n-1);
    return res*n;
}
int main(int arg,char** argv)
{
    int n;
    cin>>n;
    int f=fact(n);
    cout<<f;
    return 0;
}