#include<iostream>
#include<vector>
using namespace std;
void input(vector<vector<int>>& a)
{ for(int row=0;row<a.size();row++)
{
    for(int col=0;col<a[0].size();col++)
    {
        cin>>a[row][col];
    }
}


}
void display(vector<vector<int>> &b)
{
for(int row=0;row<b.size();row++)
{ for(int col=0;col<b[0].size();col++)
{
cout<<b[row][col]<<" ";

}
cout<<endl;

}
}
void wave(vector<vector<int>> & a)
{
for(int r=0;r<a.size();r++)
{
    if(r%2==0)
    {
        for(int c=0;c<a[0].size();c++)
        {
            cout<<a[r][c]<<" ";
        }
        
    }
    else
    {
        for( int c=a[0].size() -1;c>=0;c--)
        {
            cout<<a[r][c]<<" ";
        }
    }
    cout<<endl;
}

}
int main(int arg, char** argv)
{
 int n;
cout<<"row"<<endl;
cin>>n;
int m;
cout<<"col"<<endl;
cin>>m;

     vector<vector<int>>a(n,vector<int>(m,0));
     input(a);
     wave(a);
     
return 0;


}


