#include<iostream>
#include<vector>
using namespace std;

bool bisearch(vector<int>&arr )
{ 
int data;
cout<<"enter data";
cin>>data;
    int beg=0;
    int end=arr.size() -1;
    while(end>=beg)
    { int mid=(beg+end)/2;
    if(arr[mid]==data)
    { return true;}
    else if(arr[mid]<data)
{    beg=mid+1;}
else
{ end=mid-1;}
    }
return false;
}  
int lowbound(vector<int> & arr){
int data;
cout<<"enter data";
cin>>data;
    int beg=0;
    int end=arr.size() -1;
    while(end>=beg)
    { int mid=(beg+end)/2;
    if(arr[mid]==data)
    { if(mid-1>=0 && arr[mid-1]==arr[mid])
     end=mid-1;
     else 
     return mid;
    }
    else if(arr[mid]<data)
{    beg=mid+1;}
else
{ end=mid-1;}
    }
return -1;

}
 int upbound(vector<int> &arr)
{int data;
cout<<"enter data";
cin>>data;
    int beg=0;
    int end=arr.size() -1;
    while(end>=beg)
    { int mid=(beg+end)/2;
    if(arr[mid]==data)
    { if(mid+1<arr.size() && arr[mid+1]==arr[mid])
      beg=mid+1;
      else 
      return mid;
    }
    else if(arr[mid]<data)
{    beg=mid+1;}
else
{ end=mid-1;}
    }
return -1;

}


void input(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<"enter no";
        cin>>arr[i];
    }
}

int main(int arg ,char** argv)
{     vector<int> arr(11,0);
input(arr);
    int up=upbound(arr);
    cout<<"index"<<up;
    return 0;
    
}