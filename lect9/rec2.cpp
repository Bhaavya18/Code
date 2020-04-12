#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &a,int vdix)
{
    if(vdix==a.size())
    {
        return;
    }
    cout<<a[vdix]<<" ";
    display(a,vdix+1);
}
bool find(vector<int> a,int vdix,int data)
{   
    
    if(vdix==a.size())
    {
        return false;
    }

    
    if(data==a[vdix])
    {
      return true;
    }

  bool c= find(a,vdix+1,data);
  return c;
}
int maximum2(vector<int> & a,int vdix)
{ if(vdix== a.size()-1)
{
return a[vdix];
}
int rec=maximum2(a,vdix+1);
return max(rec,a[vdix]);

}
int minimum2(vector<int>&a,int vdix)
{
    if(vdix==a.size()-1)
    {
        return a[vdix];
    }
    int rec=minimum2(a,vdix+1);
    return min(rec,a[vdix]);
}
int lastindex(vector<int>& a,int vidx,int data)
{
    if(vidx==a.size())
    {
        return -1;
    }
    int recans=lastindex(a,vidx+1,data);
    if(recans!=-1)
    {
        return recans;

    }

    else
    {
     return  (  (a[vidx]==data)? vidx:-1);
    }
}
void solve()
{
    vector<int> a={10,6,8,10,4,5,5,6,8,-3,2,12,8,3};
    //display(a,0);
    //cout<<find(a,0,8);
    //cout<<maximum2(a,0);
    //cout<<minimum2(a,0);
    cout<<lastindex(a,0,8);
    
}
int main(int arg,char** argv)
{
    solve();
    return 0;
}