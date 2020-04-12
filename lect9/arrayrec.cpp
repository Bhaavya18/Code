#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void input(vector<int>&a,int i)
{
    if(i==a.size())
    return;
    cin>>a[i];
    input(a,i+1);
}
void display(vector<int>&a,int i)
{
    if(i==a.size())
    return;
    cout<<a[i]<<" ";
    display(a,i+1);
}
bool find(vector<int>&a,int data,int i)
{ if(i==a.size())
  return false;
    if(a[i]==data)
    return true;
   return  find(a,data,i+1);
}
int maximum(vector<int>&arr,int i)
{
    if(i==arr.size())
    return INT_MIN;
    int ans=maximum(arr,i+1);
    return max(arr[i],ans);
    
}
int minimum(vector<int>&arr,int i)
{
    if(i==arr.size())
    return INT_MAX;
    int ans=minimum(arr,i+1);
    return min(arr[i],ans);
}
void inverse(vector<int>&a,int i)
{
    if(i==a.size())
    return;
    int t=a[i];
       inverse(a,i+1);
       a[t]=i;
}

int main(int arg,char** argv)
{
    int n;
    int i=0;
    cin>>n;
    vector<int>a(n,0);
    input(a,i);
    //display(a,i);
   // int data;
   // cin>>data;
   // cout<<find(a,data,i);
   //cout<<maximum(a,i);
   //cout<<minimum(a,i);
   inverse(a,i);
   display(a,i);
    return 0;
}

