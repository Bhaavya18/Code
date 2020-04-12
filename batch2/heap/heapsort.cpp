#include<iostream>
#include<vector>
using namespace std;
 int compareto(vector<int>&arr,bool ismax,int cidx,int pidx)
{
    if(ismax)
    {
        return arr[cidx]-arr[pidx];
    }

    else
    {
        return arr[pidx]-arr[cidx];

    }
}


void downheapify(vector<int>&arr,bool ismax,int idx,int lidx)
{
    int maxidx=idx;      //we are assuming maximum to be present at zero index ie at root
    int lci=2*idx +1;
    int rci=2*idx +2;

    if(lci<lidx && compareto(arr,ismax,lci,maxidx)>0)
    {
        maxidx=lci;
    }

    if(rci<lidx && compareto(arr,ismax,rci,maxidx)>0)
    maxidx=rci;

    if(maxidx!=idx)       //if  parent does not contain maximum value then swap;
    {
        swap(arr[maxidx],arr[idx]);

        downheapify(arr,ismax,maxidx,lidx);
    }

}

int main()
{
    vector<int>arr={10,20,30,-2,-3,-4,5,6,7,8,9,22,11,13};
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
    {
        downheapify(arr,true,i,n);
    }

    for(int i=0;i<n;i++)
    {
        swap(arr[0],arr[n-1-i]);
        downheapify(arr,true,0,n-i-1);
    }


    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}
