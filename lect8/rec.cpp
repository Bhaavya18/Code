#include<iostream>
using namespace std;
void printincre(int st,int end)
{
    if(st==end+1)
    {
        return;
    }
    cout<<st<<endl;
    printincre(st+1,end);
}
void printdecre(int st,int end)
{
    if(st==end+1)
    {
        return;
    }
    printdecre(st+1,end);
    cout<<st<<endl;
}
int printdecr2(int st,int end)
{
    if(st==end)
    {
        cout<<st<<endl;
        return st-1;
    }
    int head=printdecr2(st+1,end);
    cout<<head<<endl;
    return head-1;
}
int printincre2(int st,int end)
{
    if(end==st)
    { cout<<end<<endl;
        return end+1;
    }
    int head=printincre2(st,end-1);
    cout<<head<<endl;
    return head+1;
}
int main(int arg,char** argv)
{ int st,end;
 cin>>st>>end;
 //printincre(st,end);
 //printdecre(st,end);
 printincre2(st,end);

return 0;
}