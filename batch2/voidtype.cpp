#include<iostream>
#include<vector>
using namespace std;
int  sub(string str,string ans)
{
    if(str.length()==0)
    {  
        cout<<ans<<endl;
        return 1 ;
    }
    int count=0;
    count+=sub(str.substr(1),ans);
    count+=sub(str.substr(1),ans+str[0]);
    return count;
}
vector<string>words={",.","abc","def","ghi","jkl","mno","pqrs","tuv","wxy","z","+","*&"};
int keypad(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    int idx1=str[0]-'0';
   string word1=words[idx1];
   string word2;
   for(int i=0;i<word1.length();i++)
   {
       count+=keypad(str.substr(1),ans+word1[i]);
   }
   if(str.length()>=2)      //call only possible if string length is greater than 1
   {
       int idx=idx1*10 + str[1]-'0';
       if(idx>=10 && idx<=11)    //01 case avoided
       {
           string word2=words[idx];
           for(int i=0;i<word2.length();i++)
           {
               count+=keypad(str.substr(2),ans+word2[i]);
           }
       }
   }
   return count;

}
int perm(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<str.length();i++)
    {
       string  str2=str.substr(0,i)+str.substr(i+1);
        count+=perm(str2,ans+str[i]);
    }
    return count;
}
int  dupli(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    int arr=0;          //every bit is off          //vector<bool>vis(26,false);
    for(int i=0;i<str.length();i++)
    {  int mask=1<<(str[i]-'a');
       if((arr&mask)==0)                           //if(!vis[str[i]-'a'])
       {
           arr|=mask;                               //vis[str[i]-'a']=true;
           string str2=str.substr(0,i)+str.substr(i+1);
           count+=dupli(str2,ans+str[i]);

       }
    }
    return count;
}
void basic()
{
   // cout<<sub("abc"," ");
    //cout<<keypad("101"," ");
    //cout<<perm("abc"," ");
    cout<<dupli("aba"," ");
}
void solve()
{
    basic();
}
int main()
{
    solve();
    return 0;
}