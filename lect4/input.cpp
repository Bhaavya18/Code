#include<iostream>
#include<vector>
using namespace std;
void input(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        cin>>a[i];
    }
}
void display(vector<int> & a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}
int  main(int arg,char** argv)
{
    int n;
    cin>>n;
    vector<int>a(n,0);
    input(a);
    display(a);
    return 0;
}
