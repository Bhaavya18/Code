#include<iostream>
using namespace std;
int binar(int n)
{
    int p=0;
    int pow=1;
    int rem;
    while(n!=0)
    {
         rem=n%2;
         p=p+rem*pow;
         pow=pow*10;
         n=n/2;
        
    }
    return p;
}
int deci(int n)
{
    int c=binar(n);
    int rem;
    int p=0;
    int pow=1;
    while(c!=0)
    {
        rem=c%10;
        p=rem*pow+p;
        pow*=2;
        c=c/10;


    }
    return p;
}
int decioctal(int n)
{   int rem;
    int p=0;
    int pow=1;
    while(n!=0)
    { rem=n%8;
    p=p +rem*pow;
    pow*=10;
    n=n/8;

    }
    return p;
}
int octaldeci(int n)
{ int c=decioctal(n);
    int p=0;
    int rem;
    int pow=1;
    while(c!=0)
    {
        rem=c%10;
        p=p+rem*pow;
        pow*=8;
        c=c/10;
    }
    return p;
}
int anybtb(int n,int b1,int b2)
{ int rem;
  int res=0;
  int pow=1;
  while(n!=0)
  {
      rem=n%10;
      res=res+ rem*pow;
      pow*=b1;
      n=n/10;
  }
  int r;
  int p=1;
  int res2=0;
  while(res!=0) 
  { r=res%b2;
   res2=res2+r*p;
   p*=10;
   res=res/10;
   
  }
  return res2; 
  }

int main(int arg,char** argv)
{ int n;
  cin>>n;
   // cout<<binar(n)<<endl;
    //cout<<deci(n);
    //cout<<decioctal(n)<<endl;
    //cout<<octaldeci(n);
    int b1;
    cin>>b1;
    int b2;
    cin>>b2;
    cout<<anybtb(n,b1,b2);
    return 0;
}
