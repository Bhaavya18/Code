#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>&a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]>a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
}
void input(vector<int>&a)
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
        cout<<a[i]<<" ";
    }
}
vector<int> inter(vector<int>&a,vector<int>&b)
{
    sort(a);
    sort(b);
    vector<int>c;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[i])
        {
            c.push_back(a[i]);
        }
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    vector<int>a(n,0);
    input(a);
    int n2;
    cin>>n2;
    vector<int>b(n2,0);
    input(b);
   vector<int>c=inter(a,b);
   output(c);
    return 0;
}