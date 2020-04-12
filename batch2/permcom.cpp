#include<iostream>
#include<sstream>
#include<vector>
#define vb vector<bool>
#define vvb vector<vb>
using namespace std;
int perm(vector<int>&a,int tar,string ans)    //infinite no of  coins possible
{
    if(tar==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=0;i<a.size();i++)
    {
        if(tar-a[i]>=0)
        { ostringstream str1;
        str1<<a[i];
        string geek=str1.str();
            count+=perm(a,tar-a[i],ans+geek+" ");
        }
    }
    return count;
}
int combinfi(vector<int>&a,int idx,int tar,string ans)
{
    if(tar==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<a.size();i++)
    {
        if(tar-a[i]>=0)
        {  ostringstream str1;
        str1<<a[i];
        string geek=str1.str();
            count+=combinfi(a,i,tar-a[i],ans+geek+" ");
        }
    }
    return count;
}
int combwitr(vector<int>&a,int idx,int tar,string ans)
{
 if(tar==0)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<a.size();i++)
    {
        if(tar-a[i]>=0)
        {  ostringstream str1;
        str1<<a[i];
        string geek=str1.str();
            count+=combinfi(a,i+1,tar-a[i],ans+geek+" ");   //to pass no. next to that no.
        }
    }
    return count;
}
int permwrt(vector<int>&a,int tar,string ans,vector<bool>&vis)
{
 if(tar==0)
 {
     cout<<ans<<endl;
     return 1;
 }
 int count=0;
 for(int i=0;i<a.size();i++)
 {
     if(tar-a[i]>=0 && !vis[i])
     { vis[i]=true;
      ostringstream str1;
      str1<<a[i];
      string geek=str1.str();
      count+=permwrt(a,tar-a[i],ans+geek+" ",vis);
      vis[i]=false;
     }
 }

return count;

}
int comsub(vector<int>&a,int idx,int tar,string ans)   //infinite no. of coins
{
    if(tar==0 || idx==a.size())
    {
        if(tar==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-a[idx]>=0)
    {
        ostringstream str1;
        str1<<a[idx];
        string geek=str1.str();
        count+=comsub(a,idx+1,tar,ans);
        count+=comsub(a,idx,tar-a[idx],ans+geek+" ");
    }
    return count;
}
int permsub(vector<int>&a,int idx,int tar,string ans)
{
    if(tar==0 ||idx==a.size())
    {
        if(tar==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-a[idx]>=0)
    {
        ostringstream str1;
        str1<<a[idx];
        string geek =str1.str();
        count+=permsub(a,idx+1,tar,ans);
        count+=permsub(a,0,tar-a[idx],ans+geek+" ");
    }
 return count;
}
int comsubwrt(vector<int>&a,int tar,int idx,string ans)
{
 if(tar==0 || idx==a.size())
    {
        if(tar==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-a[idx]>=0)
    {
        ostringstream str1;
        str1<<a[idx];
        string geek=str1.str();
        count+=comsubwrt(a,tar,idx+1,ans);
        count+=comsubwrt(a,tar-a[idx],idx+1,ans+geek+" ");
    }
    return count;
}
int permsubwrt(vector<int>&a,int tar,int idx,string ans,vector<bool>&vis)
{
if(tar==0 || idx==a.size())
    {
        if(tar==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    if(tar-a[idx]>=0 )
    {
        ostringstream str1;
        str1<<a[idx];
        string geek=str1.str();
        count+=permsubwrt(a,tar,idx+1,ans,vis);
        if(!vis[idx])
       { vis[idx]=true;
        count+=permsubwrt(a,tar-a[idx],0,ans+geek+" ",vis);
        vis[idx]=false;
       }
    }
    return count;
}
int queencombi(int box,int tnq,int idx,int qpsf,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count=0;
    for(int i=idx;i<box;i++)
    {
        ostringstream str1;
        str1<<i;
        string geek=str1.str();
        count+=queencombi(box,tnq,i+1,qpsf+1,ans+"q"+geek+" ");
    }
    return count;
}
int queenperm(vector<bool>&box,int tnq,int qpsf,string ans,vector<bool>&vis)
{ 
    if(qpsf==tnq )
    {
        cout<<ans<<endl;
        return 1;

    }
    int count=0;
    
    for(int i=0;i<box.size();i++)
    { ostringstream str1;
      str1<<i;
      string geek=str1.str();
      if(!vis[i])
       { vis[i]=true;
           count+=queenperm(box,tnq,qpsf+1,ans+geek+" ",vis);
       vis[i]=false;
       }
    }
return count;

}
int comsq(vector<bool>&box,int tnq,int lpql,int qpsf,string ans)
{
    if(qpsf==tnq || lpql==box.size())
    {
        if(qpsf==tnq)
        {cout<<ans<<endl;
        return 1;
        }
        return 0;
    }
    int count=0;
    count+=comsq(box,tnq,lpql+1,qpsf,ans);
    ostringstream str1;
    str1<<lpql;
    string geek=str1.str();
    ostringstream str2;
    str2<<qpsf;
    string geek2=str2.str();
    count+=comsq(box,tnq,lpql+1,qpsf+1,ans+"b"+geek+"q"+geek2+" ");
    return count;
}
int permsqueen(vector<bool>&box,int tnq,int lpql,int qpsf,string ans,vector<bool>&vis)
{
 if(qpsf==tnq || lpql==box.size())
 {
     if(qpsf==tnq)
     {
         cout<<ans<<endl;
         return 1;
     }
     return 0;
 }
 int count=0;
 count+=permsqueen(box,tnq,lpql+1,qpsf,ans,vis);
 if(!vis[lpql])
 {
     ostringstream str1;
    str1<<lpql;
    string geek=str1.str();
    ostringstream str2;
    str2<<qpsf;
    string geek2=str2.str();
    vis[lpql]=true;
    count+=permsqueen(box,tnq,0,qpsf+1,ans+"b"+geek+"q"+geek2+" ",vis);
    vis[lpql]=false;

 }

return count;


}
int queencomb(vector<vector<bool>>&board,int tnq,int lpql,int qpsf,string ans)
{
    if(qpsf==tnq)
    {
        cout<<ans<<endl;
        return 1;

    }
    int count=0;
    for(int i=lpql;i<board.size()*board[0].size();i++)
    {
        int x=i/board[0].size();
        int y=i%board[0].size();
        ostringstream str1;
        str1<<x;
        string geek=str1.str();
        ostringstream str2;
        str2<<y;
        string geek2=str2.str();
        count+=queencomb(board,tnq,i+1,qpsf+1,ans+"("+geek+","+geek2+")"+" ");
    }
    return count;
}
int queenpermu(vector<vector<bool>>&board,int tnq,int qpsf,string ans)
{
   if(qpsf==tnq)
   {
       cout<<ans<<endl;
       return 1;
   }
    int count=0;
    for(int i=0;i<board.size()*board[0].size();i++)
    {
        int x=i/board[0].size();
        int y=i%board[0].size();
        if(!board[x][y])
        {
            board[x][y]=true;
            ostringstream str1;
            str1<<x;
            string geek=str1.str();
            ostringstream str2;
            str2<<y;
            string geek2=str2.str();
            count+=queenpermu(board,tnq,qpsf+1,ans+"("+geek+","+geek2+")"+" ");
            board[x][y]=false;
        }
    }
    return count;

}

bool isvalid(vector<vector<bool>>&board,int x,int y)
{
    if(x<0||y<0||x>=board.size()||y>=board[0].size() )
            {
               
                return false;
            }
            return true;
}

bool issafe(vector<vector<bool>>&board,int r,int c)
{
    vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0},{-1,1}};
    
    for(int i=0;i<4;i++)
    {
        for(int rad=1;rad<max(board.size(),board[0].size());rad++)
        {
           int  x=r+ rad*dir[i][0];
           int  y=c+ rad*dir[i][1];
            if(isvalid(board,x,y)&& board[x][y])
            {
                // break;
                return false;
            }
            
        }
    }
    return true;
}
bool issafe2(vector<vector<bool>>&board,int r,int c)
{
 vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    
    for(int i=0;i<8;i++)
    {
        for(int rad=1;rad<max(board.size(),board[0].size());rad++)
        {
           int  x=r+ rad*dir[i][0];
           int  y=c+ rad*dir[i][1];
            if(isvalid(board,x,y)&& board[x][y])
            {
                // break;
                return false;
            }
            
        }
    }
    return true;




}
int nqueencom(vector<vector<bool>>&board,int tnq,int lpql,int qpsf,string ans)
{
  if(qpsf==tnq)
  {
      cout<<ans<<endl;
      return 1;
  }
  int count=0;
  for(int i=lpql;i<board.size()*board[0].size();i++)
  {
      int x=i/board[0].size();
      int y=i%board[0].size();
      if(issafe(board,x,y))
      {
          board[x][y]=true;
          ostringstream str1;
          str1<<x;
          string geek=str1.str();
          ostringstream str2;
          str2<<y;
          string geek2=str2.str();
          count+=nqueencom(board,tnq,i+1,qpsf+1,ans+"("+geek+","+geek2+")"+" ");
          board[x][y]=false;
      }
  }
  return count;
}
int nqueenperm(vector<vector<bool>>&board,int tnq,int qpsf,string ans)
{
 if(qpsf==tnq)
   {
       cout<<ans<<endl;
       return 1;
   }
    int count=0;
    for(int i=0;i<board.size()*board[0].size();i++)
    {
        int x=i/board[0].size();
        int y=i%board[0].size();
        if(!board[x][y] && issafe2(board,x,y))
        {
            board[x][y]=true;
            ostringstream str1;
            str1<<x;
            string geek=str1.str();
            ostringstream str2;
            str2<<y;
            string geek2=str2.str();
            count+=nqueenperm(board,tnq,qpsf+1,ans+"("+geek+","+geek2+")"+" ");
            board[x][y]=false;
        }
    }
    return count;

}
int queen(int row,int tnq,vvb &board,vb &col,vb &dia,vb &antid,string ans)
{
    if(tnq==0 || row==board.size())
    {
        if(tnq==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    for(int c=0;c<col.size();c++)
    {
        if(!col[c] && !dia[row+c] && !antid[row-c+board[0].size()-1])
        {
            col[c]=true;
            dia[row+c]=true;
            antid[row-c+board[0].size()-1]=true;
            ostringstream str1;
            str1<<row;
            string geek=str1.str();
            ostringstream str2;
            str2<<c;
            string geek2=str2.str();
            count+=queen(row+1,tnq-1,board,col,dia,antid,ans+"("+geek+","+geek2+")"+" ");
            col[c]=false;
            dia[row+c]=false;;
            antid[row-c+board[0].size()-1]=false;


        }
    }
    return count;
}
int queen2(int tnq,int n,int row,int &col,int &dia,int &antid,string ans)
{
    if(tnq==0 || row==n)
    {
        if(tnq==0)
        {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    for(int c=0;c<n;c++)
    { 
        int w=1<<c;
        int x=1<<row+c;
        int y=1<<(row-c+n-1);
        if(!(col&w) && !(dia&x) && !(antid&y) )
        {
            col^=w;
            dia^=x;
            antid^=y;
            ostringstream str1;
            str1<<row;
            string geek=str1.str();
            ostringstream str2;
            str2<<c;
            string geek2=str2.str();
            count+=queen2(tnq-1,n,row+1,col,dia,antid,ans+"("+geek+","+geek2+")"+" ");
            col^=w;
            dia^=x;
            antid^=y;

        }

    }
    return count;
}

int main()
{
    vector<int>arr={2,3,5,7};
   // cout<<perm(arr,10," ");
  //  cout<<combinfi(arr,0,10," ");
 // cout<<combwitr(arr,0,10," ");
 vector<bool>vis(5,false);
 //cout<<permwrt(arr,10," ",vis);
 //cout<<comsub(arr,0,10," ");
// cout<<permsub(arr,0,10," ");
//cout<<comsubwrt(arr,10,0," ");
cout<<permsubwrt(arr,10,0," ",vis);
//queencombi( 5,3,0,0," ");
vector<bool>box(5,false);
//cout<<queenperm(box,3,0," ",vis);
//cout<<comsq(box,3,0,0," ");
//cout<<permsqueen(box,3,0,0," ",vis);
vector<vector<bool>>board(4,vector<bool>(4,false));
//cout<<queencomb(board,4,0,0," ");
//cout<<queenpermu(board,4,0," ");
//cout<<nqueencom(board,4,0,0," ");
//cout<<nqueenperm(board,4,0," ");
//vector<bool>col(4,false);
//vector<bool>dia(7,false);
//vector<bool>antid(7,false);
//cout<<queen(0,4,board,col,dia,antid," ");
int col=0;
int dia=0;
int antid=0;
//cout<<queen2(4,4,0,col,dia,antid," ");
    return 0;
}