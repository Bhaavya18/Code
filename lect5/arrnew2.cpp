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
void output(vector<int>&a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}
bool find(vector<int>&a,int data)
{
    int i=0;
    for(i=0;i<a.size();i++)
    {
        if(a[i]==data)
        return true;
    }return false;
}
int maximum(vector<int> & a)
{
    int i;
    int x=a[0];
    for(i=0;i<a.size();i++)
    {
        if(x<a[i])
        {
            x=a[i];
        }
        
    }
    return x;
}
int minimum(vector<int> &a)
{
    int i;
    int x=a[0];
    for(i=0;i<a.size();i++)
    {
        if(x>a[i])
        {
            x=a[i];
        }
    }
    return x;
}
int main(int arg,char**argv)
{ int n;
  cin>>n;
    vector<int>a(n,0);
    input(a);
    int data;
    cin>>data;
    cout<<find(a,data);
    //cout<<maximum(a);
    //cout<<minimum(a);
    return 0;
}