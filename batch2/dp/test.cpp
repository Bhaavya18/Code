#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

void display(vector<vector<int>>&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr[0].size();j++)
         {cout<<arr[i][j]<<" ";}
         cout<<endl;
    }
    cout<<endl;
}

int fib01(int n)   //this function contains repeated calls
{
    if(n<=1)
    return n;

    int ans=fib01(n-1)+fib01(n-2);

    return ans;

}

int fib02(int n,vector<int>&dp)  //memeorization-to reduce repeated calls
{
    if(n<=1)
    {
        dp[n]=n;
        return n;
    }

    if(dp[n]!=0)    //if dp vector already contains ans then don't make fib(n-1)+fib(n-2) call instead directly ans is returned
    {
        return dp[n];
    }

    int ans=fib02(n-1,dp)+fib02(n-2,dp);

    dp[n]=ans;  //on and off statement of dp

    return ans;
}

int fib03(int n,vector<int>&dp)   //tabulation
{
    for(int i=0;i<dp.size();i++)
    {
        if(i<=1)
        {
            dp[i]=i;
            continue;
        }

        dp[i]=dp[i-1]+dp[i-2];

    }

    return dp[n];
}

int mazepath01(int sr,int sc,int er,int ec,vector<vector<int>>&dp)  //memorization
{
    if(sr==er && sc==ec)
    {
        //return 1;
        dp[sr][sc]=1;
        return 1;

    }
     
     int count=0;

     if(dp[sr][sc]!=0)
     return dp[sr][sc];

     if(er==ec && dp[sr][sc]!=0)   //for optimization;  if mirror image
     return dp[sr][sc];

    if(sc+1<=ec)
     count+=mazepath01(sr,sc+1,er,ec,dp);

    if(sr+1<=er)
    count+=mazepath01(sr+1,sc,er,ec,dp);

    dp[sr][sc]=count;

    if(er==ec)
    dp[sr][sc]=count;
  

  return count;
}

int mazepath_01t(int er,int ec,vector<vector<int>>&dp)
{
   // int count=0;
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
        {
            if(sr==er && sc==ec)
            {
               dp[sr][sc]=1;
               continue;
            }
          
          int count=0;
            if(sc+1<=ec)
            count+=dp[sr][sc+1];

            if(sr+1<=er)
            count+=dp[sr+1][sc];

            dp[sr][sc]=count;
        }
    }

return dp[0][0];

}

int mazepath_D(int sr,int sc,int er,int ec,vector<vector<int>>&dp)
{
    if(sr==er && sc==ec)
    {
        //return 1;
        dp[sr][sc]=1;
        return 1;

    }
     
     int count=0;

     if(dp[sr][sc]!=0)
     return dp[sr][sc];

     if(er==ec && dp[sr][sc]!=0)   //for optimization;  if mirror image
     return dp[sr][sc];

    if(sc+1<=ec)
     count+=mazepath_D(sr,sc+1,er,ec,dp);

    if(sr+1<=er)
    count+=mazepath_D(sr+1,sc,er,ec,dp);

    if(sr+1<=er && sc+1<=ec)
    count+=mazepath_D(sr+1,sc+1,er,ec,dp);

    dp[sr][sc]=count;

    if(er==ec)
    dp[sr][sc]=count;
  

  return count;
}

int mazepath_Dt(int er,int ec,vector<vector<int>>&dp)
{
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
        {
            if(sc==ec && sr==er)
            {
                dp[sr][sc]=1;
                continue;
            }
            int count=0; 

            if(sc+1<=ec)
            count+=dp[sr][sc+1];

            if(sr+1<=er)
            count+=dp[sr+1][sc];

            if(sr+1<=er && sc+1<=ec)
            count+=dp[sr+1][sc+1];

            dp[sr][sc]=count;

        }
    }

    return dp[0][0];
}

int mazepath_multi(int sr,int sc,int er,int ec,vector<vector<int>>&dp)
{
    if(sr==er && sc==ec)
    {
        dp[sr][sc]=1;
        return 1;
    }

    int count=0;

    if(dp[sr][sc]!=0)
    return dp[sr][sc];

    for(int i=1;sc+i<=ec;i++)
    count+=mazepath_multi(sr,sc+i,er,ec,dp);
    
    for(int i=1;sr+i<=ec;i++)
    count+=mazepath_multi(sr+i,sc,er,ec,dp);

    
    for(int i=1;sc+i<=ec && sr+i<=er;i++)
    count+=mazepath_multi(sr+i,sc+i,er,ec,dp);

    dp[sr][sc]=count;

    return count;
}

int mazepath_multitab(int er,int ec,vector<vector<int>>&dp)
{
    for(int sr=er;sr>=0;sr--)
    {
        for(int sc=ec;sc>=0;sc--)
        {
            if(sr==er && sc==ec)
            {
                dp[sr][sc]=1;
                continue;
            }

            int count=0;
            for(int i=1;sc+i<=ec;i++)
            count+=dp[sr][sc+i];

            for(int i=1;sr+i<=er;i++)
            count+=dp[sr+i][sc];

            for(int i=1;sc+i<=ec && sr+i<=er ;i++)
            count+=dp[sr+i][sc+i];

            dp[sr][sc]=count;
        }
    }

    return dp[0][0];
}
 
 int paths_D(int st,int end)
 {
      if(st==end)
     {  
         return 1;
     }

     int count=0;

     for(int i=1;i<=6;i++)
     {
         if(st+i<=end)
        {
             count+=paths_D(st+i,end);
         }
         
     }
      
     return count;
 }

 int paths_DM(int st,int end,vector<int>&dp)
 {
      if(st==end)
     {   dp[st]=1; 
         return 1;
     }

     int count=0;
     if(dp[st]!=0)
     return dp[st];

     for(int i=1;i<=6;i++)
     {
         if(st+i<=end)
        {
             count+=paths_DM(st+i,end,dp);
         }
         
     }

     dp[st]=count;
      
     return count;
 }

int paths_DT(int st,int end,vector<int>&dp)
{
    for(int i=end;i>=st;i--)
    {
        if(i==end)
        {
            dp[i]=1;
            continue;
        }
         
         int count=0;

        for(int j=1;j<=6;j++)
        {
            if(j+i<=end)
           count+=dp[i+j];
        }

        dp[i]=count;
    }

    return dp[0];
}

int paths_O(int st,int end,vector<int>&arr)
{
    if(st==end)
    return 1;

    int count=0;

    for(int i=0;i<arr.size();i++)
    {
        if(st+arr[i]<=end)
        count+=paths_O(st+arr[i],end,arr);
    }

    return count;
}

int paths_OM(int st,int end,vector<int>&arr,vector<int>&dp)
{
     if(st==end)
    {  dp[st]=1;
       return 1;
    } 

    int count=0;

    if(dp[st]!=0)
    return dp[st];

    for(int i=0;i<arr.size();i++)
    {
        if(st+arr[i]<=end)
        count+=paths_OM(st+arr[i],end,arr,dp);
    }
 
    dp[st]=count;
    return count;
}

int paths_OT(int st,int end,vector<int>&arr,vector<int>&dp)
{
    for(int i=end;i>=st;i--)
    {
        if(i==end)
        {
            dp[i]=1;
            continue;
        }

        int count=0;

        for(int j=0;j<arr.size();j++)
        {
            if(i+arr[j]<=end)
            count+=dp[i+arr[j]];
        }

        dp[i]=count;
    }

    return dp[0];
}
//************leetcode ques 70*************************************************************************************************//
int mincostclimbing_(int n,vector<int>&cost,vector<int>&dp)
{
     if(n<=1)
     {
         dp[n]=cost[n];
        return cost[n];
     }

    int c1=0;
     int c2=0;

     if(dp[n]!=0)
     return dp[n];

     if(n-1>=0)
      c1+=mincostclimbing_(n-1,cost,dp);

      if(n-2>=0)
      c2+=mincostclimbing_(n-2,cost,dp);

      int ans=min(c1,c2) +cost[n];
      dp[n]=ans;

      return ans;
  

}

int mincostclimbing_t(int n,vector<int>&cost,vector<int>&dp)
{
    for(int i=0;i<=n;i++)
    {
        if(i==0)
        {
            dp[i]=cost[i];
            continue;
        }
        int c1=0;
        int c2=0;

        if(i-1>=0)
        c1+=dp[i-1];

        if(i-2>=0)
        c2+=dp[i-2];

        dp[i]=min(c1,c2) +cost[i];
    }

    return dp[n];
}

int mincostclimbing(vector<int>&cost)
{
     cost.push_back(0);
    cout<<cost.size ()<<endl;
    vector<int>dp(cost.size(),0);
    return mincostclimbing_(cost.size()-1,cost,dp);

}
//*********leetcode ques64****************************************************************************************************************///
int pathsum(int sr,int sc,vector<vector<int>>&grid)
{   
    int n=grid.size()-1;
    int m=grid[0].size()-1;


    if(sr==n && sc==m)
    {
        return 1;
    }
   
     int c1=1e6,c2=1e6;
    if(sc+1<=m)
     c1=pathsum(sr,sc+1,grid);

    if(sr+1<=n)
     c2=pathsum(sr+1,sc,grid);

    int ans=min(c1,c2) + grid[sr][sc];

    return ans;
    
}
int pathsum_M(int sr,int sc,vector<vector<int>>&grid,vector<vector<int>>&dp)
{   
    int n=grid.size()-1;
    int m=grid[0].size()-1;


    if(sr==n && sc==m)
    {
        dp[sr][sc]=grid[sr][sc];
        return grid[sr][sc];
    }
   
     int c1=1e6,c2=1e6;

     if(dp[sr][sc]!=0)
     return dp[sr][sc];

    if(sc+1<=m)
     c1=pathsum_M(sr,sc+1,grid,dp);

    if(sr+1<=n)
     c2=pathsum_M(sr+1,sc,grid,dp);

    int ans=min(c1,c2) + grid[sr][sc];

    dp[sr][sc]=ans;

    return ans;
    
}
int pathsum_t(int sr,int sc,vector<vector<int>>&grid)
{
    int n=grid.size()-1;
    int m=grid[0].size()-1;
    for(int i=n;i>=sr;i--)
    {
        for(int j=m;j>=sc;j--)
        {
            if(i==n && j==m)
            continue;

            int c1=1e6,c2=1e6;

            if(i+1<=n)
            c1=grid[i+1][j];

            if(j+1<=m)
            c2=grid[i][j+1];

            grid[i][j]+=min(c1,c2);

        }
    }

    return grid[0][0];
}
//***************************************************************************************************************************************8//

int pairupandsingleup(int n)
{
    if(n<=1)
    return 1;

    int single=pairupandsingleup(n-1);
    int pair=(n-1)*pairupandsingleup(n-2);  //or u can  write function call in for(int i=0;i<n-1;i++) instead of mutiplying with n-1;optimized

  return single+pair;

}                                         
int pairupsingleup_M(int n,vector<int>&dp)
{
    if(n<=1)
    {
        dp[n]=n;
        return 1;
    }

    if(dp[n]!=0)
    return dp[n];

     int single=pairupsingleup_M(n-1,dp);
    int pair=(n-1)*pairupsingleup_M(n-2,dp);

    dp[n]=single+pair;

    return single+pair;

}

int pairupsingleup_T(int n,vector<int>&dp)
{
    for(int i=0;i<=n;i++)
    {
        if(i<=1)
        {
            dp[i]=1;
            continue;
        }

     int single, pair;
        if(i-1>=0)
         single=dp[i-1];

        if(i-2>=0)
         pair=(i-1)*dp[i-2];

        dp[i]=single+pair;
    }

    return dp[n];
}

int pairupsingleup_F(int n)
{
    int a=1;
    int b=1;
    int ans;

    for(int i=2;i<=n;i++)
    {
        ans=b+(i-1)*a;
        a=b;
        b=ans;
    }

    return ans;
}
//** **** division of elements into k subsets***************************************************************************************//
int ksubsets(int n,int k)
{
   if(n==k)
   return 1;
   
   if(n<k)
   return 0;
   
   if(k==1)
   return 1;

   int count=0;

   if(n-1>=0 && k-1>=0)
   count+=ksubsets(n-1,k-1);   //newset creation

   if(n-1>=0)
   count+=k*ksubsets(n-1,k); //addition in already created sets (previous set)  (arrangement)

return count;

}

int ksubsets_M(int n,int k,vector<vector<int>>&dp)
{
    if(n==k)
    {
        dp[n][k]=1;
        return 1;
    }

    if(k==1)
    {
        dp[n][k]=1;
        return 1;
    }

    if(n<k)
    {
        dp[n][k]=0;
        return 0;
    }

    if(dp[n][k]!=0)
    return dp[n][k];


    int count=0;
    if(n-1>=0 && k-1>=0)
    count+=ksubsets_M(n-1,k-1,dp);

    if(n-1>=0)
    count+=k*ksubsets_M(n-1,k,dp);

    dp[n][k]=count;

    return count;
}

 int ksubsets_T(int n,int k,vector<vector<int>>&dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i==j)
           {
           dp[i][j]=1;
            continue;
        }

       if(j==1)
    {
        dp[i][j]=1;
        continue;
    }

    if(i<j)
    {
        dp[i][j]=0;
        continue;
    }


    int count=0;
    if(i-1>=0 && j-1>=0)
    count+=dp[i-1][j-1];

    if(i-1>=0)
    count+=j*dp[i-1][j];

    dp[i][j]=count;


        }
    }

    return dp[n][k];
}
//*************GOLD MINE********************************************************************************************************************//
vector<vector<int>>dir={{0,1},{-1,1},{1,1}};
int goldmine(int x,int y,vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    if(y==matrix[0].size()-1)
   {   dp[x][y]=matrix[x][y];
       return  matrix[x][y];
   }
    
    if(dp[x][y]!=0)
    return dp[x][y];


    int maxans=-1e7;

    for(int i=0;i<3;i++)
    {
        int r=x+dir[i][0];
        int c=y+dir[i][1];

        if(r>=0 && c>=0 && r<matrix.size() && c<matrix[0].size() )
        {
            maxans=max(maxans,goldmine(r,c,matrix,dp));
        }
    }

    dp[x][y]=maxans+matrix[x][y];
    
    return dp[x][y];
}

int goldmine_T(vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    for(int i=matrix.size()-1;i>=0;i--)
    {
        for(int j=matrix[0].size()-1;j>=0;j--)
        {
            if(j==matrix[0].size()-1)
            {
                dp[i][j]=matrix[i][j];
                continue;
            }
         int maxans=-1e6;
            for(int d=0;d<3;d++)
            {
                int r=i+dir[d][0];
                int c=j+dir[d][1];

                if(r>=0 && c>=0 && r<matrix.size() && c<matrix[0].size())
                  maxans=max(maxans,dp[r][c]);
            }

            dp[i][j]=maxans+matrix[i][j];
        
        }
    }

    int maxans=-1e6;
    for(int i=0;i<dp.size();i++)
    {
        maxans=max(maxans,dp[i][0]);
    }

    return maxans;
}


int goldmine_(vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    //vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size()));
    int maxans=-1e7;
    for(int i=0;i<matrix.size();i++)
    {
       maxans=max(maxans,goldmine(i,0,matrix,dp));
    }

    return maxans;
}



//*******leetcode 45**************************************************************************************************//
int minJump(int idx,vector<int>&arr)
{
    if(idx>=arr.size()-1)
    return 0;

    //if(arr[idx]==0)
   // return (int)1e7;

     int minans=(int)1e7;
    for(int jump=1;jump<=arr[idx] && idx+jump<arr.size();jump++)  //zero testcase already handled
    {
        int minjump=minJump(idx+jump,arr);

        if(  minjump!=(int)1e7 && minjump+1<minans)
        minans=minjump+1;
    }

    return minans;
}
int minJump_M(int idx,vector<int>&arr,vector<int>&dp)
{
    if(idx==arr.size()-1)
        return 0;

    //if(arr[idx]==0)
   // return (int)1e7;
   if(dp[idx]!=0)
   return dp[idx];

     int minans=(int)1e7;
    for(int jump=1;jump<=arr[idx] && idx+jump<arr.size();jump++)  //zero testcase already handled
    {
        int minjump=minJump_M(idx+jump,arr,dp);

        if(  minjump!=(int)1e7 && minjump+1<minans)
        minans=minjump+1;
    }
    dp[idx]=minans;

    return minans;
}

int minJump_T(vector<int>&arr,vector<int>&dp)
{
    for(int i=arr.size()-1;i>=0;i--)
    {
        if(i==arr.size()-1)
        {
            dp[i]=0;
            continue;
        }
      int minans=(int)1e7;

        for(int jump=1;jump<=arr[i] && jump+i<arr.size();jump++)
        {
            int minjump=dp[i+jump];
            if(minjump+1<minans)
            minans=minjump+1;

        }

        dp[i]=minans;
    }
    return dp[0];
}
void display1(vector<int>&dp)
{
    for(int i=0;i<dp.size();i++)
   { cout<<dp[i]<<" "; }

    cout<<endl;
}
int  MinJump_OP(vector<int>&arr)
{
   // queue<int>que;
  //  que.push(arr[0]);
    int ce=arr[0];
    int ne=0;
    int steps=1;

    for(int i=0;i<=ce;i++)
    {
        ne=max(ne,i+arr[i]);

        if(ne>=arr.size()-1)
        return steps;

        if(i==ce)
        {
            ce=ne;
            steps++;
        }
    }

    return steps;
}

//*****************************************maximum size square sub matrix with all one's*************************//
int maxpossiblesquare=0;
int maxsizesq(int r,int c,vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    if(r==arr.size() || c==arr[0].size())
    {
       // dp[r][c]=arr[r][c];
        return 0;
    }

    int minans=0;
    if(dp[r][c]!=-1)
    return dp[r][c];

    int down=maxsizesq(r+1,c,arr,dp);
    int right=maxsizesq(r,c+1,arr,dp);
    int diag=maxsizesq(r+1,c+1,arr,dp);

    if(arr[r][c]==1)
    minans=min(min(down,right),diag)+1;

    dp[r][c]=minans;

    maxpossiblesquare=max(maxpossiblesquare,dp[r][c]);

    return dp[r][c];


}

int maxsizesq_T(vector<vector<int>>&arr,vector<vector<int>>&dp)
{
    int maxans_=0;
    for(int i=arr.size()-1;i>=0;i--)
    {
        for(int j=arr[0].size()-1;j>=0;j--)
        {


            if(arr[i][j]==1)
            dp[i][j]=min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]))+1;   //out of bound condition handled by taking dp of extra size
            else
            {
                dp[i][j]=0;
            }
            
           
            maxans_=max(maxans_,dp[i][j]);

        }
    }
    return maxans_;
}
///****** tile of size 1*m in n*m matrix******************************************************************************************// 
int tileno_M(int n,int m,vector<int>&dp)
{
    if(n<=m)
    {
        dp[n]=(n==m)?2:1;
        return (n==m)?2:1;
    }

    if(dp[n]!=0)
    return dp[n]; 

    int hori=tileno_M(n-1,m,dp);
    int verti=tileno_M(n-m,m,dp);

    dp[n]=hori+verti;

    return dp[n];
}

int tileno_T(int n,int m,vector<int>&dp)
{
    for(int i=0;i<=n;i++)
    {
        if(i<=m)
        {
            dp[i]=(i==m)?2:1;
            continue;
        }
          
       int hori=dp[i-1];
        int verti=dp[i-m];

        dp[i]=hori+verti;


    }
    return dp[n];
}

int tileno_O(int n,int m)
{
    list<int>ll;
   for(int i=0;i<m;i++)
   {
     ll.push_back(1);
   }

   for(int i=m;i<=n;i++)
   {
       int hori=ll.back();
       int verti=ll.front();

       ll.push_back(hori+verti);
       ll.pop_front();
   }

   return ll.back();
}
//************************coin change problem********************************************************//
int infiniteperm(int tar,vector<int>&arr,vector<int>&dp)
{
    if(tar==0)
    {
        dp[tar]=1;
        return 1;
    }

       if(dp[tar]!=0)
      return dp[tar];

      int count=0;

    for(int i=0;i<arr.size();i++)
    {
        if(tar-arr[i]>=0)
       count+=infiniteperm(tar-arr[i],arr,dp);
      
    }
    dp[tar]=count;
    return count;
}

int infiniteperm_T(int tar,vector<int>&arr,vector<int>&dp)
{
    for(int i=0;i<=tar;i++)
    {
       if(i==0)
       {
           dp[i]=1;
           continue;
       }
      int count=0;

    for(int j=0;j<arr.size();j++)
    {
        if(i-arr[j]>=0)
       count+=dp[i-arr[j]];
      
    }
    dp[i]=count;

    }

    return dp[tar];
}

int infinitecombi_T(int tar,vector<int>&arr,vector<int>&dp)
{
    dp[0]=1;
    for(int i=0;i<arr.size();i++)
    {
        for(int t=1;t<dp.size();t++)
        {
            if(t-arr[i]>=0)
            dp[t]+=dp[t-arr[i]];
        }
    }

    return dp[tar];
}

int minimumcoins_H(int tar,vector<int>&arr,vector<int>&dp)
{
     if(tar==0)
     {  dp[tar]=0;  
         return 0;
     }
      
      if(dp[tar]!=0)
      return dp[tar];
    
      int height=1e6;
      for(int i=0;i<arr.size();i++)
      {
          if(tar-arr[i]>=0)
          {
              int recans=minimumcoins_H(tar-arr[i],arr,dp); 
               height=min(height,recans+1);
          }
      }
      dp[tar]=height;
      return height;

}

int minimumcoins_T(int tar,vector<int>&arr,vector<int>dp)
{
    for(int i=0;i<dp.size();i++)
    dp[i]=1e6;

    dp[0]=0;    //all other indexes of dp contain 1e6

    for(int i=1;i<=tar;i++)
    {
        for(int j=0;j<arr.size();j++)
        {   
            if(i-arr[j]>=0)
             dp[i]=min(dp[i],dp[i-arr[j]]+1);
        }
    }

    return dp[tar];
}
//**********************subsequence approach combi***************************************
int combsubwrt(int tar,int idx,vector<int>&arr,vector<vector<int>>&dp)   //prefer tabulation instead of memorization
{
    if(tar==0 || idx==arr.size())
    {
        if(tar==0)
        {
            dp[idx][tar]=1;
            return 1;
        }
        return 0;
    }
     if(dp[idx][tar]!=0)
     return dp[idx][tar];

     int count=0;
    if(tar-arr[idx]>=0)
    count+=combsubwrt(tar-arr[idx],idx+1,arr,dp);

    count+=combsubwrt(tar,idx+1,arr,dp);
    dp[idx][tar]=count;

    return count;
}


int dptraversal(int tar,vector<int>&arr,vector<vector<int>>&dp)   //subsequence method
{
     dp[0][0]=1; 
    for(int i=1;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
             if(dp[i-1][j]!=0)
             dp[i][j]+=1;

             if( j-arr[i-1]>=0 && dp[i-1][j-arr[i-1]]!=0)
             dp[i][j]+=1;
        }

    }
    return dp[arr.size()][tar];
}
//***********************************knapsnack problem*****************//
int knapsnack_M(int cap,int idx,vector<int>&arr,vector<int>&val,vector<vector<int>>&dp) //single coin
{
    if(cap==0 || idx==arr.size())   //cap==0 condition not necessary only reduces unwanted calls we want to traverse whole array
    return 0;
    
     if(dp[idx][cap]!=0)
     return dp[idx][cap];


    int picked=0,unpicked=0;
    if(cap-arr[idx]>=0)
    picked=knapsnack_M(cap-arr[idx],idx+1,arr,val,dp)+val[idx];

    unpicked=knapsnack_M(cap,idx+1,arr,val,dp);

    return dp[idx][cap]=max(picked,unpicked);   

}
int knapsnack_T(int tar,vector<int>&arr,vector<int>&val,vector<vector<int>>&dp)  //single coin
{
    dp[0][0]=0;
    for(int i=1;i<dp.size();i++)
    {
        for(int j=0;j<dp[0].size();j++)
        {
            int a=0,b=0;
            if(j-arr[i-1]>=0)
            a=dp[i-1][j-arr[i-1]] +val[i-1];  //picking element

            b=dp[i-1][j];  //unpicked

            dp[i][j]=max(a,b);
        }
    }
    return dp[dp.size()-1][dp[0].size()-1];
}

int unboundedknapsnack(int tar,vector<int>&arr,vector<int>&val,vector<int>&dp)   //infinite no of coins available
{
    for(int i=0;i<arr.size();i++)
    {
        for(int t=1;t<=tar;t++)
        {
            if(t-arr[i]>=0)
            dp[t]=max(dp[t],dp[t-arr[i]]+val[i]);
        }
    }

    return dp[tar];
}
//****************************string based****************************************//
vector<vector<bool>> pallindromesubstring(string str)
{
    vector<vector<bool>>dp(str.length(),vector<bool>(str.length(),0));
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j<str.length();j++,i++)
        {
            if(gap==0)
            dp[i][j]=true;

          else if(str[i]==str[j])
            {
                if(gap==1)
                dp[i][j]=true;

               else if(dp[i+1][j-1])
                dp[i][j]=true;
            }

        }
    }
    return dp;
}

int  longestpallindromesubstring(string str,vector<vector<int>>&dp)
{
    vector<vector<bool>>ispallindrome=pallindromesubstring(str);
    
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j<str.length();j++,i++)
        {
            if(gap==0)
            dp[i][j]=1;

            else if(str[i]==str[j] && gap==1)
                dp[i][j]=2;

          else if(str[i]==str[j] && ispallindrome[i+1][j-1]) //mid part of substring is pallindrome or not
          dp[i][j]=dp[i+1][j-1]+2;  

            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
            
        }
    }
    return dp[0][str.length()-1];
}
int longestpallindromesubseq(string str,vector<vector<int>>&dp)
{
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j<str.length();i++,j++)
        {
            if(gap==0)
            dp[i][j]=1;

            else  if(str[i]==str[j])
            dp[i][j]=dp[i+1][j-1]+2;  //+2 for end characters add dp[i+1][j-1];

            else
            dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
        
        }
    }

    return dp[0][str.length()-1];
}
int countpallindromesubseq(string str,vector<vector<int>>&dp)
{
    for(int gap=0;gap<str.length();gap++)
    {
        for(int i=0,j=gap;j<str.length();i++,j++)
        {
            if(gap==0)
            dp[i][j]=1;

         else  if(str[i]==str[j])
          {  dp[i][j]=dp[i+1][j-1]+1;   //in answers of mid part append aa(repeating char) so we will get all answers except aa
            dp[i][j]+=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];  //rest answers calculate karo
          }

          else
          {
              dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
          }
    

        }
    }
    return dp[0][str.length()-1];
}
//*************************************Longest Increasing Subsequence********************************//
int LIS_rec(int idx,vector<int>&arr,int lnum,string ans)
{
    if(idx==arr.size())
    {
        cout<<ans<<endl;
        return 1;
    }

    int count=0;
    count+=LIS_rec(idx+1,arr,lnum,ans);

    for(int i=idx+1;i<arr.size();i++)
    {
        if(arr[i]>lnum)
        count+=LIS_rec(i,arr,arr[i],ans+to_string(arr[i])+" ");
    }

    return count;

}
vector<int> LIS_T(vector<int>&arr)
{
    vector<int>dp(arr.size(),1);
    int maxans=1;
    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            dp[i]=max(dp[i],dp[j]+1);
        }
        maxans=max(maxans,dp[i]);
    }
    cout<<maxans<<endl;
    return dp;
}
vector<int>LDS_DP(vector<int>&arr)
{
    vector<int>dp(arr.size(),1);
    int maxans=1;
    for(int i=arr.size()-2;i>=0;i--)
    {
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[i]>arr[j])  //for equal elements
            dp[i]=max(dp[i],dp[j]+1);
        }
        maxans=max(maxans,dp[i]);
    }
    cout<<maxans<<endl;
    return dp;
}
vector<int>LBS_DP(vector<int>&arr)
{
    vector<int>LBS(arr.size(),1);
    vector<int>LIS=LIS_T(arr);
    vector<int>LDS=LDS_DP(arr);
    int maxans=1;
    for(int i=0;i<arr.size();i++)
    {
        LBS[i]=LDS[i]+LIS[i]-1;
        maxans=max(maxans,LBS[i]);
    }
    cout<<maxans<<endl;
    return LBS;
}
vector<int> maxincresumsubseq(vector<int>&arr)
{
    vector<int>dp(arr.size(),0);
    for(int i=0;i<arr.size();i++)
    dp[i]=arr[i];

    int maxans=1;
    for(int i=1;i<arr.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            dp[i]=max(dp[i],arr[i]+dp[j]);
        }
        maxans=max(maxans,dp[i]);
    }
    cout<<maxans<<endl;
    return dp;
}
int minimumnoOfdeletion(vector<int>&arr)   //minimum of deletions to be done to make array sorted
{
    vector<int>LIS=LIS_T(arr);   // make changes in if(arr[i]>=arr[j])
    int maxans=1;
    for(int ele:LIS)
     maxans=max(maxans,ele);

     return arr.size()-maxans;
}
//********************cut type*******************************************************//
int mcm_M(int si,int ei,vector<int>&arr,vector<vector<int>>&dp)
{
    if(si+1==ei)       //for single matrix cost of multiplication is zero
         return 0;

    if(dp[si][ei]!=0)
    return dp[si][ei];

    int minans=1e6;
    string ans="";
    for(int cut=si+1;cut<ei;cut++)
    {
        int left=mcm_M(si,cut,arr,dp);
        int right=mcm_M(cut,ei,arr,dp);
        int cost=left+arr[si]*arr[cut]*arr[ei]+right;
        minans=min(minans,cost);
    }
    dp[si][ei]=minans;
    return minans;
}
pair<int,string> mcm_Mstring(int si,int ei,vector<int>&arr,vector<vector<pair<int,string>>>&dp)
{
     if(si+1==ei)       //for single matrix cost of multiplication is zero
    {  string str=string(1,(char)(si+'A'));
        return {0,str};
    }

    if(dp[si][ei].first!=0)
    return dp[si][ei];

    pair<int,string>minans={1e6,""};
    for(int cut=si+1;cut<ei;cut++)
    {
        pair<int,string> left=mcm_Mstring(si,cut,arr,dp);
        pair<int,string>right=mcm_Mstring(cut,ei,arr,dp);
        int cost=left.first+arr[si]*arr[cut]*arr[ei]+right.first;
        if(cost<minans.first)
        {
            minans.first=cost;
            minans.second="("+left.second+right.second+")";
        }
    }
    dp[si][ei]=minans;
    return minans;

}
int mcm_T(vector<int>&arr,vector<vector<int>>&dp)
{
    for(int gap=1;gap<arr.size();gap++)
    {
        for(int si=0,ei=gap;ei<arr.size();si++,ei++)
        {
            if(si+1==ei)  //to avoid writing this start from gap=2
            continue;
             int minans=1e6;
        for(int cut=si+1;cut<ei;cut++)
       {
        int left=dp[si][cut];
        int right=dp[cut][ei];
        int cost=left+arr[si]*arr[cut]*arr[ei]+right;
        minans=min(minans,cost);
       }
       dp[si][ei]=minans;

        }  
    }
    return dp[0][arr.size()-1];
}
int mcm_TS(vector<int>&arr,vector<vector<int>>&dp)
{
    vector<vector<string>>sdp(arr.size(),vector<string>(arr.size(),""));
    for(int gap=1;gap<arr.size();gap++)
    {
        for(int si=0,ei=gap;ei<arr.size();si++,ei++)
        {
            if(si+1==ei)
            {
                sdp[si][ei]=string(1,(char)(si+'A'));
                continue;
            }
               int minans=1e6;
          for(int cut=si+1;cut<ei;cut++)
         {
            int left=dp[si][cut];
            int right=dp[cut][ei];
            int cost=left+arr[si]*arr[cut]*arr[ei]+right;
            if(minans>cost)
            {
                minans=cost;
                dp[si][ei]=cost;
                sdp[si][ei]="("+sdp[si][cut]+sdp[cut][ei]+")";
            }
         }

        }  
    }
    cout<<sdp[0][arr.size()-1]<<endl;
    return dp[0][arr.size()-1];
}
int minpallindromiccut(string str,int si,int ei,vector<vector<int>>&dp,vector<vector<bool>>&ispali)
{
    if(si==ei)
    return 0;

    if(ispali[si][ei])
    {
        dp[si][ei]=0;
        return 0;
    }

    if(dp[si][ei]!=0)
    return dp[si][ei];

    int mincut=1e6;
    for(int cut=si;cut<ei;cut++)
    {
        int left=minpallindromiccut(str,si,cut,dp,ispali);
        int right=minpallindromiccut(str,cut+1,ei,dp,ispali);
        int tcuts=left+right+1;
        mincut=min(mincut,tcuts);

    }
    dp[si][ei]=mincut;
    return mincut;
}
int minpallindromiccut_T(string str,vector<vector<int>>&dp,vector<vector<bool>>&ispali)
{
    for(int gap=1;gap<str.length();gap++)
    {
        for(int si=0,ei=gap;ei<str.length();si++,ei++)
        {
              if(si==ei)
              continue;

            if(ispali[si][ei])
             continue;

       int mincut=1e6;
       for(int cut=si;cut<ei;cut++)
       {
        int left=minpallindromiccut(str,si,cut,dp,ispali);
        int right=minpallindromiccut(str,cut+1,ei,dp,ispali);
        int tcuts=left+right+1;
        mincut=min(mincut,tcuts);

       }
      dp[si][ei]=mincut;

    }

    }
    return dp[0][str.length()-1];
}
//*************************leetcode ques312*******************************************//
int maxburstcost(int si,int ei,vector<int>&arr,vector<vector<int>>&dp)
{
    int l=(si-1==-1)?1:arr[si-1];
    int r=(ei+1==arr.size())?1:arr[ei+1];
   
   if(dp[si][ei]!=0)
   return dp[si][ei];

    int maxans=0;
    for(int cut=si;cut<=ei;cut++)
    {
        int left=(cut==si)?0:maxburstcost(si,cut-1,arr,dp);
        int right=(cut==ei)?0:maxburstcost(cut+1,ei,arr,dp);
        int cost=left+ l*arr[cut]*r + right;
        maxans=max(cost,maxans);

    }
    dp[si][ei]=maxans;
    return maxans;
}
int maxburst_T(int si,int ei,vector<int>&arr,vector<vector<int>>&dp)
{
    for(int gap=0;gap<arr.size();gap++)
    {
        for(si=0,ei=gap;ei<arr.size();si++,ei++)
        {
         int l=(si-1==-1)?1:arr[si-1];
         int r=(ei+1==arr.size())?1:arr[ei+1];

       int maxans=0;
         for(int cut=si;cut<=ei;cut++)
       {
        int left=(cut==si)?0:dp[si][cut-1];
        int right=(cut==ei)?0:dp[cut+1][ei];
        int cost=left+ l*arr[cut]*r + right;
        maxans=max(cost,maxans);

        }
      dp[si][ei]=maxans;

        }
    }
    return dp[0][arr.size()-1];
}
//****************optimal BST******************************************//
int optimalBST(int si,int ei,int height,vector<int>&arr,vector<int>&freq,vector<vector<int>>&dp)
{
    //if(dp[si][ei]!=0)
   // return dp[si][ei];

    int mycost=1e6;
    for(int cut=si;cut<=ei;cut++)
    {
        int left=(cut==si)?0:optimalBST(si,cut-1,height+1,arr,freq,dp);
        int right=(cut==ei)?0:optimalBST(cut+1,ei,height+1,arr,freq,dp);
        int cost=left+ height*freq[cut]+right;
        mycost=min(mycost,cost);
    }
    dp[si][ei]=mycost;
    return mycost;
}
int suminrange(vector<int>&freq,int si,int ei)
{
    int sum=0;
    for(int i=si;i<=ei;i++)
    {
        sum+=freq[i];
    }
    return sum;
}
int optimalBST1(int si,int ei,vector<int>&arr,vector<int>&freq,vector<vector<int>>&dp) //time complexity o(n^4)
{
    if(dp[si][ei]!=0)
    return dp[si][ei];

    int mycost=1e6;
    for(int cut=si;cut<=ei;cut++)
    {
        int left=(cut==si)?0:optimalBST1(si,cut-1,arr,freq,dp);
        int right=(cut==ei)?0:optimalBST1(cut+1,ei,arr,freq,dp);
        int cost=left+suminrange(freq,si,ei)+right;
        mycost=min(mycost,cost);
    }
    dp[si][ei]=mycost;
    return mycost;
}
int optimalBST2(int si,int ei,vector<int>&arr,vector<int>&freq,vector<int>&psum,vector<vector<int>>&dp) //o(n^3)
{
    if(dp[si][ei]!=0)
    return dp[si][ei];

    int mycost=1e6;
    for(int cut=si;cut<=ei;cut++)
    {
        int left=(cut==si)?0:optimalBST2(si,cut-1,arr,freq,psum,dp);
        int right=(cut==ei)?0:optimalBST2(cut+1,ei,arr,freq,psum,dp);
        int cost=left+psum[ei]-((si-1==-1)?0:psum[si-1])+right;   // psum=[a,a+b,a+b+c]
        mycost=min(mycost,cost);
    }
    dp[si][ei]=mycost;
    return mycost;
}
int optimalBST_T(int si,int ei,vector<int>&arr,vector<int>&freq,vector<int>&psum,vector<vector<int>>&dp)
{
    for(int gap=0;gap<arr.size();gap++)
    {
        for(si=0,ei=gap;ei<arr.size();si++,ei++)
        {
            int mycost=1e6;
         for(int cut=si;cut<=ei;cut++)
        {
          int left=(cut==si)?0:optimalBST2(si,cut-1,arr,freq,psum,dp);
          int right=(cut==ei)?0:optimalBST2(cut+1,ei,arr,freq,psum,dp);
          int cost=left+psum[ei]-((si-1==-1)?0:psum[si-1])+right;   // psum=[a,a+b,a+b+c]
          mycost=min(mycost,cost);
         }
           dp[si][ei]=mycost;
        }
    }
    return dp[0][arr.size()-1];
}
//***********************string cut more questions*********************************//
int longestcommonsubseq(string str1,int i,string str2,int j,vector<vector<int>>&dp)
{
  if(i==str1.length() || j==str2.length())
  return 0;

    int ans=0;
    if(str1[i]==str2[j])
    ans=longestcommonsubseq(str1,i+1,str2,j+1,dp);
    
    else
    {
        ans=max(longestcommonsubseq(str1,i,str2,j+1,dp),longestcommonsubseq(str1,i+1,str2,j,dp));
    }
    
   dp[i][j]=ans;
   return ans;
}
//***********edit distance*************//
int editdistance(string str1,int i,string str2,int j,vector<vector<int>>&dp)
{

    int count=0;
    if(str1[i]==str2[j])
    count=editdistance(str1,i+1,str2,j+1,dp);

    else
    {
        str1[i]+=str2[j];
    }
    
}
void set2()
{
    int n=10;
    //cout<<pairupandsingleup(n)<<endl;
    vector<int>dp(n+1,0);
    //  cout<<pairupsingleup_T(n,dp)<<endl;
 // cout<<pairupsingleup_F(n);
     // display1(dp);
     vector<int>arr={2,3,5,7};
   //  vector<int>dp(arr.size(),0);
    // cout<<minJump_T(arr,dp)<<endl;
   // cout<<MinJump_OP(arr);
   //  display1(dp);
   //vector<vector<int>>dp(6,vector<int>(4,0));
   //cout<<ksubsets_T(5,3,dp)<<endl;
   vector<vector<int>>matrix={{0,1,1,0,1},{1,1,0,1,0},{0,1,1,1,0},{1,1,1,1,0},{1,1,1,1,1},{0,0,0,0,0}};
   // vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
  // cout<<goldmine_(matrix,dp)<<endl;
  //cout<<goldmine_T(matrix,dp)<<endl;
 // maxsizesq(0,0,matrix,dp);
  //cout<<maxpossiblesquare<<endl;
 // cout<<maxsizesq_T(matrix,dp)<<endl;  //for this either make dp size extra ie +1 matrix.size() && +1 matrix[0].size() or handle in for loop in function only
 // cout<<maxans_<<endl;
 //cout<<tileno_T(7,4,dp)<<endl;   //output 5
 //cout<<tileno_O(7,4);  
// cout<<infiniteperm(10,arr,dp)<<endl;
   // display1(dp);
   // display(dp);
}
void target()
{
      
    int cap=7;
   // vector<int>dp(n+1,0);
     vector<int>arr={2,5,1,3,4};
     vector<int>val={15,14,10,45,30};
     //vector<vector<int>>dp(arr.size()+1,vector<int>(cap+1,0));
     vector<int>dp(cap+1,0);
     //cout<<combsubwrt(10,0,arr,dp)<<endl;
 //  cout<<dptraversal(10,arr,dp)<<endl;
 //cout<<knapsnack_M(50,0,arr,val,dp)<<endl;
 //cout<<knapsnack_T(7,arr,val,dp)<<endl;
     //display(dp);
     cout<<unboundedknapsnack(7,arr,val,dp)<<endl;
     display1(dp);

    //cout<<infiniteperm(10,arr,dp)<<endl;
   // cout<<infiniteperm_T(4,arr,dp)<<endl;
 //cout<<minimumcoins_T(11,arr,dp)<<endl;

    // display1(dp);
}
void stringproblems()
{
    string str="amrmsra";
    vector<vector<int>>dp(str.length(),vector<int>(str.length(),0));
   // cout<<longestpallindromesubstring(str,dp)<<endl;
  // cout<<longestpallindromesubseq(str,dp)<<endl;
  cout<<countpallindromesubseq(str,dp)<<endl;
    display(dp);

   
   // display(dp);
}
void LS()
{
   vector<int>arr={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
  // vector<int>arr={0,8,4,12,8,8,8,8};  //written for equal to changes
  //cout<<LIS_rec(-1,arr,-1e6," ")<<endl;
  //vector<int>dp(arr.size(),1);
 // dp=LIS_T(arr);
 //vector<int>dp1=LDS_DP(arr);
 //vector<int>dp=LBS_DP(arr);
 //vector<int>dp=maxincresumsubseq(arr);
 // display1(dp);
 cout<<minimumnoOfdeletion(arr)<<endl;
}
void cut()
{
    //vector<int>arr={40,20,30,10,30};
   // vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
   // cout<<mcm_M(0,arr.size()-1,arr,dp)<<endl;
  //  cout<<mcm_TS(arr,dp)<<endl;
 // string str="ababcc";
//vector<vector<bool>> ispali=pallindromesubstring(str);
//vector<vector<int>>dp(str.length(),vector<int>(str.length(),0));
//cout<<minpallindromiccut(str,0,str.length()-1,dp,ispali)<<endl;
//cout<<minpallindromiccut_T(str,dp,ispali)<<endl;
 //vector<int>arr={3,1,5,8};
 //vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
 //cout<<maxburst_T(0,arr.size()-1,arr,dp)<<endl;
  //  display(dp);
   vector<int>arr={10,12,20};
   vector<int>freq={34,8,50};
   vector<int>psum(arr.size(),0);
   for(int i=0;i<arr.size();i++)
   {
       if(i!=0)
       psum[i]+=psum[i-1];

       psum[i]+=freq[i];
   }
   
   vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));

   cout<<optimalBST_T(0,arr.size()-1,arr,freq,psum,dp)<<endl;
   display(dp);
   // vector<vector<pair<int,string>>>dp(arr.size(),vector<pair<int,string>>(arr.size(),{0,""}));
  //  pair<int,string>ans=mcm_Mstring(0,arr.size()-1,arr,dp);
   // cout<<ans.first<<"->"<<ans.second;

}
int main()
{
   // int n=10;
  //  vector<vector<int>>dp(3,vector<int>(3,0));
   // cout<<fib01(10)<<endl;
   // cout<<fib02(10,dp)<<endl;
    //cout<<fib03(10,dp)<<endl;
   // display(dp);
  // cout<<mazepath_01t(2,2,dp)<<endl;
  //cout<<mazepath_D(0,0,2,2,dp)<<endl;
  //cout<<mazepath_Dt(2,2,dp)<<endl;
  //cout<<mazepath_multi(0,0,2,2,dp)<<endl;
  //cout<<mazepath_multitab(2,2,dp);
  // display(dp);
//cout<<paths_D(0,10);
//vector<int>dp(4,0);
//cout<<paths_DM(0,10,dp)<<endl;
//cout<<paths_DT(0,3,dp)<<endl;
//vector<int>arr={2,3,7,5};
//cout<<paths_O(0,10,arr);
//cout<<paths_OM(0,10,arr,dp)<<endl;
//cout<<paths_OT(0,10,arr,dp)<<endl;
//for(int i=0;i<dp.size();i++)
//cout<<dp[i]<<" ";
// vector<int>cost={0,1,0,0};
//  cost.push_back(0);
//     cout<<cost.size ()<<endl;
//     vector<int>dp(cost.size(),0);
//     cout<< mincostclimbing_t(cost.size()-1,cost,dp)<<endl;
//cout<<mincostclimbing(cost);

//vector<vector<int>>grid={{1,3,1},{1,5,1},{4,2,1}};
//vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),0));
//cout<<pathsum_M(0,0,grid,dp)<<endl;
//cout<<pathsum_t(0,0,grid)<<endl;
//display(grid);
//set2();
//target();
//stringproblems();
//LS();
//cut();
vector<int>values={6,21,4,27,23,46,9,5,15};
vector<int>weight={4,2,5,5,7,8,7,10,5};
vector<vector<int>>dp(values.size()+1,vector<int>(10,0));
cout<<knapsnack_M(9,0,weight,values,dp);

  return 0;

}
