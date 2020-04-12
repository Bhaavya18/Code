#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int>>&a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            cin>>a[i][j];
        }
    }
}
void display(vector<vector<int>>&a)
{
    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void waveh(vector<vector<int>>&a)
{
    for(int i=0;i<a.size();i++)
    {
        if(i%2==0)
        {
            for( int j=0;j<a[0].size();j++)
            {
                cout<<a[i][j]<<" ";
            }
        }
        else
        {
            for( int j=a[0].size()-1;j>=0;j--)
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}
void exitpoint(vector<vector<int>>&a)
{int dir=0;
int r=0;
int c=0;

while(true)
{ dir=(dir+a[r][c])%4;
    if(dir==0)
    {
        c++;
        if(c==a[0].size())
       {cout<<r<<" "<<(c-1);
       break;
       }
    }
     else if(dir==1)
    {
        r++;
        if(r==a.size())
       { cout<<(r-1)<<" "<<c;
        break;
       }
    }
    else if(dir==2)
    {
        c--;
        if(c==-1)
        {
            cout<<r<<" "<<(c+1);
            break;
        }
    }
    else if(dir==3)
    {
        r--;
        if(r==-1)
        {
            cout<<(r+1)<<" "<<c;
            break;
        }
    }
}  

}
void spiralp(vector<vector<int>>&a)
{
    int rmin=0;
    int cmin=0;
    int cmax=a[0].size()-1;
    int rmax=a.size()-1;
    int tne=(a.size()*a[0].size());
    while(tne!=0)
    { for(int i=cmin;i<=cmax && tne!=0;i++)
      {
          cout<<a[rmin][i]<<" ";
          tne--;
      }
      rmin++;
    
      for(int i=rmin;i<=rmax && tne!=0;i++)
      {
          cout<<a[i][cmax]<<" ";
          tne--;
      }
      cmax--;
      
      for(int i=cmax;i>=cmin && tne!=0;i--)
      {
          cout<<a[rmax][i]<<" ";
          tne--;
      }
      rmax--;
      
      for(int i=rmax;i>=rmin && tne!=0;i--)
      {
          cout<<a[i][cmin]<<" ";
          tne--;
      }
      cmin++;

    }
}
void transpose(vector<vector<int>>& a) 
{
    for(int i=0;i<a.size();i++)
    {
        for( int j=i;j<a[0].size();j++)
        {
            swap(a[i][j],a[j][i]);

        }
    }
}                                //valid transpose if n*n matrix
void colswap(vector<vector<int>>&a)
{ int c1=0;
int c2=a[0].size()-1;
  while(c1<c2)
    for(int i=0;i<a.size();i++)
    {
     swap(a[i][c1],a[i][c2]);
     c1++;
     c2--;
    }
}
void rowswap(vector<vector<int>>&a)
{
    int r1=0;
    int r2=a.size()-1;
    while(r1<r2)
    {
        swap(a[r1],a[r2]);
        r1++;
        r2--;
    }
}

void clockanti(vector<vector<int>>& a,int p)
{ transpose(a);
if(p==1)
{
    colswap(a);
    display(a);
}
else
{
    rowswap(a);
    display(a);
}      

}
int main(int arg,char** argv)
{int n;
cin>>n;
int m;
cin>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    input(a);
   // waveh(a);
  // exitpoint(a);
  //spiralp(a);
  int p;
  cin>>p;
  clockanti(a,p);
    return 0;
}

