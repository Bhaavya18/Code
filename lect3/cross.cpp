#include <iostream>
using namespace std;
void cross(int n)
{ int nst=1;
  int nsp=(n/2)+1;
 int r;
 int p=0;
 for(r=1;r<=n;r++)
 {   
         for(int csp=0;csp<p;csp++ )
         {
             cout<<" ";
         }
             if(r<n/2)
             {
                 p++;
             }
             else if(r>(n/2)+1)
             {
               p--;
             }
         
     
    for(int cst=1;cst<=nst;cst++)
     {
         cout<<"*";
     }
     for(int csp=1;csp<=nsp;csp++)
     {
         cout<<" ";
     }
    
      for(int cst=1;cst<=nst;cst++)
       { if(r==(n/2)+1 && n%2!=0)
          {continue;}
         cout<<"*";
       }
    
     cout<<endl;
     if(r<=n/2)
     {   
         nsp-=2;
     }
     else 
     {   if(nsp==-2)
         {
           nsp+=4;
         } 
         nsp+=2;
     }

 }

}
int main(int arg,char** argv)
{
    int n;
    cout<<"enter n";
    cin>>n;
    cross(n);
    return 0;
}