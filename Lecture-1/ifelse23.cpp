#include<iostream>
using namespace std;
int main (int argv,char** args)
{int a;
cout<<"enter a"<<endl;
cin>>a;
int b;
cout<<"enter b"<<endl;
cin>>b;
int c;
cout<<"enter c"<<endl;
cin>>c;
if(a>b && a>c)
cout<<a;
else if(b>c&& b>a)
cout<<b;
else
cout<<c;
return 0;
}