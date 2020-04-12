#include<iostream>
#include <vector>
using namespace std;

void input(vector<int>& arr)
{ for(int i=0;i<arr.size();i++)
{ cout<<" enter numbers";
    cin>>arr[i];}

}
void display(vector<int>&arr)
{ for(int i=0;i<arr.size();i++)
{ cout<<arr[i]<<" ";}

}
int min2(vector<int>& arr)
{ input(arr);
    int x= arr[0];
for(int i=0;i<arr.size();i++)
{
    if(x>arr[i])
    { x=arr[i];}
}
return x;

}


int main( int arg,char** argv)
{
vector<int>arr(5,0);
int c=min2(arr);
cout<<c;
return 0;
}