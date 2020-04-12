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
void sum(vector<vector<int>> &a,vector<vector<int>> &b)
{ if(a.size()==b.size() && a[0].size()==b[0].size())
{
    for(int row=0;row<a.size();row++)
    { for(int col=0;col<a[0].size();col++)
{
    a[row][col]+=b[row][col];

}

    }
    display(a);
}

}
int main(int arg, char** argv)
{ int n;
cout<<"row"<<endl;
cin>>n;
int m;
cout<<"col"<<endl;
cin>>m;

     vector<vector<int>>a(n,vector<int>(m,0));
     vector<vector<int>>b(n,vector<int>(m,0));
     input(a);
     cout<<"input 2"<<endl;
     input(b);
     sum(a,b);

return 0;

}