#include<iostream>
#include<vector>
using namespace std;
vector<string>  perm(string str)
{ 
    if(str.length()==1)
    {
        vector<string>base;
        base.push_back(str);
        return base;
    }
    char ch=str[0];
    vector<string>myans;
    vector<string>recans=perm(str.substr(1));
    for(string s: recans)
    {
        for(int i=0;i<=s.length();i++)
        {
            string st=s.substr(0,i) +ch +s.substr(i);
            myans.push_back(st);
        }
    }
    
return myans;

}
int main()
{  for(string s: perm("abc"))
   {
       cout<<s<<" ";
   }
  return 0;
}