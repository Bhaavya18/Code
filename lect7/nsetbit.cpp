#include<iostream>
using namespace std;
int main(int arg, char** argv)
{int n;
cout<<"enter no";
cin>>n;
int l=0;
int count=0;
    while(n!=0)
    {
        if((n &1)!=0 && l<32)
        {
            count++;
        }
        n>>=1;
        l++;
    
    }
    cout<<count;
    return 0;
}