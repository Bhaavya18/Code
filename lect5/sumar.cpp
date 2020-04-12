#include<iostream>
#include<vector>
using namespace std;
void input(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<"enter no";
        cin>>a[i];
    }
}

void display(vector<int> &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
}



void sum(vector<int> &a,vector<int> &b)
{ vector<int> c(a.size()+b.size(),0);
int i=a.size()-1;
int j=b.size()-1;
int k=c.size()-1;
int cary=0;
while(i>=0||j>=0||cary!=0)
{ 
int sum=cary;
if(i>=0)
sum=sum+a[i];
if(j>=0)
sum=sum+b[j];
int rem=sum%10;
cary=sum/10;
c[k]=rem;
k--;
j--;
i--;
}
display(c);
}
int main(int arg,char** argv)
{ vector<int> a(5,0);
input(a);
cout<<"now input for array 2";
vector<int> b(1,0);
input(b);
sum(a,b);



}