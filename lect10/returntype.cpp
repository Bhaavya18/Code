#include<iostream>
#include<vector>

using namespace std;
string removehi(string str)
{ 
    if(str.length()==0)
    return " ";
    char ch=str[0];
    if(str.length()>1 && str.substr(0,2)=="hi")
    return removehi(str.substr(2));
    else
    return ch +removehi(str.substr(1));
}
string removehi2(string str)
{
    if(str.length()==0)
    return " ";
    char ch=str[0];
    if(str.length()>1 && str.substr(0,2)=="hi")
    {
        if(str[2]=='t'&& str.length()>2)
        {
            string st=str.substr(0,3);
            return st + removehi2(str.substr(3));
        }

        else
        return removehi2(str.substr(2));
    }
    else
    {
        return ch+ removehi2(str.substr(1));
    }
}
//======================================================================================================================================
string removedup(string str,int vidx)
{
    if(str.length()==vidx)
    {
        return string(1,str[vidx-1]);
    }
    if(str[vidx-1]!=str[vidx] && vidx!=0)
    return str[vidx-1] + removedup(str,vidx+1);
    else
     return removedup(str,vidx+1);
}
void dup2(string str,string ans)
{
    if(str.length()==0)
    {
        cout<<ans<<endl;
        return ;
    }
    if(ans[ans.length()-1]!=str[0])
    {
        ans+=str[0];
    }
    dup2(str.substr(1),ans);
}
vector<string>subseq(string str)
{
    if(str.length()==0)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    char ch=str[0];
    vector<string>smallans=subseq(str.substr(1));
    vector<string>myans(smallans);
    for(string s:smallans)
    {
        myans.push_back(ch+s);
    }
    return myans;
}
//===================permutations=================================================================================================
vector<string> perm(string str)
{
    if(str.length()==0)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    char ch=str[0];
    vector<string>smallans=perm(str.substr(1));
    vector<string>myans;
    for(string s:smallans)
    {
        for(int i=0;i<s.length();i++)
        {
            string st=s.substr(0,i)+ch+s.substr(i);
            myans.push_back(st);
        }
    }
    return myans;
}
//==============================================================================================================================================
vector<string>mazepath_D(int sr,int sc,int er,int ec)
{
    if(sc==ec && sr==er)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    vector<string>myans;
    if(sc+1<=ec)
    {
        vector<string>hori=mazepath_D(sr,sc+1,er,ec);
        for(string s:hori)
        {
            myans.push_back("h"+s);
        }

    }
    if(sr+1<=er)
    {
        vector<string>ver=mazepath_D(sr+1,sc,er,ec);
        for(string s:ver)
        {
            myans.push_back("v"+s);
        }
    }
    if(sr+1<=er && sc+1<=ec)
    {
        vector<string>dia=mazepath_D(sr+1,sc+1,er,ec);
        for(string s: dia)
        {
            myans.push_back("d"+s);
        }

    }
    return myans;
}
int maxh(int sr,int sc,int er,int ec )
{
    if(sr==er && sc==ec)
    {
        return 0;
    }
     int hor=0,ver=0,dia=0;
     if(sc+1<=ec)
     {
         hor=maxh(sr,sc+1,er,ec);
     }
     if(sr+1<=er)
     {
         ver=maxh(sr+1,sc,er,ec);
     }
     if(sc+1<=ec && sr+1<=er)
     {
        dia=maxh(sr+1,sc+1,er,ec);
     }
     return max(dia,max(hor,ver))+1;
} 
//==================================================================================================================================================
bool issafe(int x,int y,int er,int ec,vector<vector<bool>>&board)
{
    if(x<0 ||y<0||x>er||y>ec||board[x][y])
    {
        return false;
    }
    return true;
}
vector<vector<int>>direction={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
vector<string> dir={"r","1","u","2","L","3","d","4"};
int floodfill(int sr,int sc,int er,int ec,vector<vector<bool>> &board,string ans)
{  
    if(sc==ec && sr==er)
    {   cout<<ans<<endl;
        return 1;
    }
   int count=0;
   int x;
   int y;
   board[sr][sc]=true;
   for(int i=0;i<8;i++)
   {
        x=sr+direction[i][0];
        y=sc+direction[i][1];
        if(issafe(x,y,er,ec,board))
       { 
         count+=floodfill(x,y,er,ec,board,ans+dir[i]);

        }
   }
   board[sr][sc]=false;
return count;

} 
//=====================ratgame(bomb present at specific locations)====================================================================================
bool issafe(int x,int y,vector<vector<bool>>&board)
{
    if(x<0||y<0||x>=board.size()||y>=board[0].size()||board[x][y])
    {
        return false;
    }
    return true;
}
int ratgame(int sr,int sc,int er,int ec,vector<vector<bool>>&board)
{
    if(sr==board.size()-1 && sc==board[0].size()-1)
    {  //cout<<ans<<endl;
        return 1;
    }
    int x;
    int y;
    int count=0;
    board[sr][sc]=true;
    for(int i=0;i<8;i++)
    {
        x=sr+direction[i][0];
        y=sc+direction[i][1];
        if(issafe(x,y,board))
        {
          count+=ratgame(x,y,er,ec,board);

        }
    }
    board[sr][sc]=false;
    return count;
}

//===============================================================================================
vector<string>words={"_","+-/","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","*()%","#@$"};
vector<string>keypad(string str)
{
    if(str.length()==0)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    char ch=str[0];
    string word=words[ch -'0'];
    vector<string> smallans= keypad(str.substr(1));
    vector<string>myans;
    for(string s:smallans)
    {
        for(int i=0;i<word.length();i++)
        {
            myans.push_back(word[i]+s);
        }
    }
    if(str.length()>1&& ch!=0)
    {
       int num= (ch-'0')*10 +(str[1]-'0');
       if(num<12)
       {   string word2=words[num];
           vector<string>sm2=keypad(str.substr(2));
           for(string s:sm2)
           {
               for(int i=0;i<word2.length();i++)
               {
                   myans.push_back(word2[i]+s);
               }
           }
       }
        
            }
    return myans;        
}
 
vector<string>wordform(string str)   //encoding alphabets mapped from 1 to 26  
{
    if(str.length()==0)
    {
        vector<string>base;
        base.push_back(" ");
        return base;
    }
    char ch=str[0];
    char ch1=(char)((str[0]-'1')+'a');
    vector<string>myans;
    if(ch=='0')
    {
        return wordform(str.substr(1));

    }
    vector<string>smallans=wordform(str.substr(1));
    for(string s:smallans)
    {
        myans.push_back(s+ch1);

    }
    if(str.length()>1)
    {
        int num=(ch-'0')*10 +(str[1]-'0');
        if(num<=26)
        {
            char ch2=(char)(num-1 +'a');
            vector<string>sm2=wordform(str.substr(2));
            for(string s:sm2)
            {
                myans.push_back(s+ch2);
            }
        }
    }
    return myans;


}
//=============================================================

void solve()
{
   // cout<<removehi("hhihihiiii");
   //cout<<removehi2("hithihiii");
  // cout<<removedup("aabbccda",0);
 // dup2("aabbccda"," ");
 //for(string s:subseq("abcd"))
 //{
     //cout<<s;
// }
//for(string s:mazepath_D(0,0,2,2))
//{
   // cout<<s<<endl;
//}
//cout<<maxh(0,0,2,2);
//vector<vector<bool>>board(3,vector<bool>(3,false));
//cout<<floodfill(0,0,2,2,board,"");
//vector<vector<bool>>board(5,vector<bool>(5,false));
//board[0][0]=true;
//board[0][4]=true;
//board[1][0]=true;
//board[2][1]=true;
//board[2][2]=true;
//board[3][0]=true;
//board[4][2]=true;
//cout<<ratgame(0,1,4,3,board);
//for(string s:perm("abc"))
//{
    //cout<<s<<" ";
//}
for(string s:keypad("1011"))
{
    cout<<s<<endl;
}
//for(string s:wordform("1124"))
//{
   // cout<<s;
//}

}
int main()
{
    solve();
    return 0;
}