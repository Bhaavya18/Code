#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
vector<string> mazepath_m(int sr,int sc,int er,int ec)
{
    if((sr==er) && (sc==ec))
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    vector<string>hor;
    vector<string>ver;
    vector<string>dia;
    vector<string>myans;
    for(int i=1;(i+sc)<=ec;i++)
    {  
        hor=mazepath_m(sr,sc+i,er,ec);
        for(string s:hor)
        {  ostringstream str1;
            str1<<i;
            string geek=str1.str();
            myans.push_back("h"+geek+s);
        }
    }
    for(int i=1;(i+sr)<=er;i++)
    {
        ver=mazepath_m(sr+1,sc,er,ec);
        for(string s:ver)
        {
            ostringstream str1;
            str1<<i;
            string geek=str1.str();
            myans.push_back(s+"v"+geek);
        }
    }
    for(int i=1;(i+sc)<=ec &&(i+sr)<=er;i++)
    {
        dia=mazepath_m(sr+1,sc+1,er,ec);
        for(string s:dia)
        {   ostringstream str1;
            str1<<i;
            string geek=str1.str();
            myans.push_back(s+"d"+geek);
        }
    }
    return myans;
}
int main(int arg,char** argv)
{
    for(string s:mazepath_m(0,0,2,2))
    {
        cout<<s<<endl;
    }
    return 0;
}