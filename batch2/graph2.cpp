#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<stack>
using namespace std;
class Edge{
 public:
 int v=0;
 int w=0;
 Edge(int v,int w)
 {
     this->v=v;
     this->w=w;
 }   
};
//int n=7;
int n=7;
vector<vector<Edge*>>graph(n,vector<Edge*>());
void display(vector<vector<Edge*>>&graph)
{
    for(int i=0;i<graph.size();i++)
    {    cout<<i<<"->";
        for(Edge* e:graph[i])
        cout<<"("<<e->v<<","<<e->w<<")"<<" ";
        cout<<endl;

    }

}
void addedge(int u,int v,int w,vector<vector<Edge*>>&graph)
{
    if(u<0||v<0||u>=graph.size()||v>=graph.size())
    return;
    graph[u].push_back(new Edge(v,w));
   //a graph[v].push_back(new Edge(u,w));
}
void constructg()
{
   addedge(0,1,2,graph);
    addedge(0,3,9,graph);
    addedge(1,2,3,graph);
    addedge(2,3,4,graph);
    addedge(3,4,2,graph);
    addedge(4,5,2,graph);
    addedge(4,6,33,graph);
    addedge(5,6,8,graph);
                                                 //   addedge(0,1,10);
                                                  //   addedge(0,3,10);
                                                  //   addedge(0,6,10);
                                                  // addedge(1,2,10);
  //  addedge(0,1,10);
  //  addedge(1,2,10);
  //  addedge(2,3,10);
 //  addedge(0,4,10);
 //  addedge(5,4,10);
 //  addedge(5,6,10);
  // addedge(6,7,10);
   // addedge(7,3,10);                                    // addedge(2,3,40);
                                                  // addedge(2,5,10);
                                                  // addedge(3,4,2);
                                                  //  addedge(4,5,2);
                                                  //   addedge(4,6,3);
                                                  //   addedge(5,6,8);
}
void removeedge(int u,int v)
{
    int i=0;
    while(i<=graph[u].size())
    {
        Edge *e=graph[u][i];
        if(e->v==v)
        break;
        i++;

    }
    int j=0;
    while(i<=graph[v].size())
    {
        Edge*e=graph[v][j];
        if(e->v==v)
        break;
        j++;

    }
    graph[u].erase(graph[u].begin()+i);
    graph[v].erase(graph[v].begin()+j);
}
void removevertex(int u)
{
    while(graph[u].size()!=0)
    {
       Edge*e=graph[u][graph[u].size()-1];
       removeedge(u,e->v);

    }
}
void haspath(int src,int dest,vector<bool>&vis,string psf)
{  cout<<psf<<endl;
    if(src==dest)
   { // cout<<psf<<endl;                  //if we don't apply base case then we cannot  call of (4,6) even if we backtrack it
                                          //because after 6 we can not make further calls
    return;
   }
    vis[src]=true;
    for(Edge*e:graph[src])
    {
        if(!vis[e->v])
        {
            ostringstream str1;
            str1<<e->v;
            string geek=str1.str();
            haspath(e->v,dest,vis,psf+geek);
        }
    }

}
int allpath(int src,int dest,vector<bool>&vis,string psf,int esf)
{
    if(src==dest)
    {
       cout<<psf<<endl;
       cout<<esf<<endl;
        return 1;
    }
    vis[src]=true;
    int count=0;
    for(Edge*e:graph[src])
    {
       if(!vis[e->v])
        {   ostringstream str1;
        str1<<e->v;
        string geek=str1.str();
            count+= allpath(e->v,dest,vis,psf+geek ,esf+e->w);
        }
    }
    vis[src]=false;
   return count;
}
int lsf=-1;
string lpsf=" ";
int swsf=1e8;
string sf=" ";
void largepath(int src,int dest,vector<bool>&vis,string psf,int esf)
{
    if(src==dest)
    {
        if(lsf<esf)
        {
            lsf=esf;  //it checks whether value of esf is greater or not
            lpsf=psf;
        }
        if(swsf>esf)
        {
            swsf=esf;
            sf=psf;
        }
    }
    vis[src]=true;
     for(Edge*e:graph[src])
    {
       if(!vis[e->v])
        {   ostringstream str1;
        str1<<e->v;
        string geek=str1.str();
         largepath(e->v,dest,vis,psf+geek ,esf+e->w);
          
        }
    }
    vis[src]=false;

}
void bsf(int src,int desti,vector<bool>&vis)
{
    queue<int>que;
    que.push(src);
    que.push(-1);
    int cycle=0;
    int level=0;
    while(que.size()!=1)   
    {
        int rvtx=que.front();
        que.pop();
        if(vis[rvtx])
        {
            cout<<"cycle:"<<++cycle<<endl;
            continue;
        }
        if(rvtx==desti)
        {
            cout<<"goal:"<<level<<endl;

        }
        vis[rvtx]=true;
        for(Edge*e:graph[rvtx])
        {  
            if(!vis[e->v])                  //**
            que.push(e->v);
        }
         if(que.front()==-1)
         {
             level++;
             que.pop();
             que.push(-1);
         }
    }
}
void bsf2(int src,int dest,vector<bool>&vis)
{
    queue<int>que;
    que.push(src);
    int cycle=0;
    int level=0;
    bool isdest=false;
    while(que.size()!=0)
    {
        int size=que.size();
        while(size-->0)
        {
            int rvtx=que.front();
            que.pop();
            if(vis[rvtx])
            {
                cout<<"cycle:"<<++cycle<<endl;
                continue;
            }
            if(rvtx==dest && !isdest)
            {
                cout<<"goal:"<<level<<endl;
                isdest=true;
            }
            vis[rvtx]=true;
            for(Edge*e:graph[rvtx])
            {
                if(!vis[e->v])
                que.push(e->v);
            }
        }
        level++;
    }
}
int  hametonian(int src,int osrc,int nvtx,vector<bool>&vis,string ans)
{
    if(nvtx==graph.size()-1)
    {
        bool flag=false;
        for(Edge*e:graph[src])
        {
            if(e->v==osrc)
           { 
               cout<<"cycle:"<<ans<<endl;
               flag=true;
           }
        }
        if(!flag)
       {  
            cout<<"path:"<<ans<<endl;
       }
       return 1;
    }
    int count=0;
    
    vis[src]=true;
    for(Edge*e:graph[src])
    {
        if(!vis[e->v])
       {
           ostringstream str1;
           str1<<e->v;
           string geek=str1.str();
       count+= hametonian(e->v,osrc,nvtx+1,vis,ans+geek);
       }
    }
    vis[src]=false;
    return count;

}
bool bipart(int src,vector<int>&vis)
{
    queue<pair<int,int>>que;
    que.push(make_pair(src,0));
    int cycle=0;
    bool flag=true;
    while(que.size()!=0)
    {
        int size=que.size();
        while(size-->0)
        {
            pair<int,int>rvtx=que.front();
            que.pop();
            if(vis[rvtx.first]!=-1)
            {
                if(vis[rvtx.first]!=rvtx.second)
              { cout<<"conflict"<<endl;
               flag=false;
              }
               continue;    //if cycle ie(2/0) (2/0) occurs twice then also we need to continue
            }
            vis[rvtx.first]=rvtx.second;
            for(Edge*e:graph[rvtx.first])
            {
                if(vis[e->v]==-1)
                {
                    que.push({e->v,(rvtx.second+1)%2});
                }
            }
        }

    }
    return flag;

}
void isbipartite(int src,vector<int>&vis)
{
    for(int i=0;i<vis.size();i++)
    {
        if(vis[i]==-1)
        cout<<i<<(boolalpha)<<bipart(i,vis)<<endl;
    }
}
vector<int>st;
void toposort(int src,vector<bool>&vis)
{
    vis[src]=true;
    for(Edge*e:graph[src])
    {
        if(!vis[e->v])
        toposort(e->v,vis);
    }
    st.push_back(src);
}
void tops(vector<bool>&vis)
{
    for(int i=0;i<vis.size();i++)
    {
        if(!vis[i])
        {
            toposort(i,vis);
        }
    }
}
void khansalgo()
{
    vector<int>indegree(graph.size(),0);
    for(int i=0;i<graph.size();i++)
    {
        for(Edge*e:graph[i])
        {
            indegree[e->v]+=1;
        }
    }
    queue<int>que;
    stack<int>sta;
    for(int i=0;i<indegree.size();i++)
    {
        if(indegree[i]==0)
        {
          que.push(i);
        }
    }
    while(que.size()!=0)
  {  int rvtx=que.front();
    que.pop();
    sta.push(rvtx);
    for(Edge*e:graph[rvtx])
    {
       indegree[e->v]-=1;

        if(indegree[e->v]==0)
       {      
           que.push(e->v);
       }
    }

  }
  if(sta.size()!=graph.size())
  {
      cout<<"cycle"<<endl;
  }
  else
  {    while(sta.size()!=0)
    {
        cout<<sta.top()<<" ";
        sta.pop();
    }
  }
}
class dpair{
public:
    int vtx=0;
    int par=0;
    int w=0;
    int wsf=0;
    dpair(int vtx,int par,int w,int wsf)
    {
        this->vtx=vtx;
        this->par=par;
        this->w=w;
        this->wsf=wsf;
    }
    bool operator <(dpair const& o) const     //we are keeping output constant and variable const
    {
        return this->wsf > o.wsf ;
    }

};
vector<vector<Edge*>>dg(n,vector<Edge*>());
void dijikstar(int src,vector<bool>&vis)
{
     priority_queue<dpair>que;
  que.push(dpair(src,-1,0,0));
  vector<int>ans(n,0);
while(que.size()!=0)
{
    dpair rvtx=que.top();
    que.pop();
  //  ans.push_back(rvtx.wsf);  if write this here then due to presence of cycle things will be added twice
    if(vis[rvtx.vtx])
    {
        continue;
    }
    if(rvtx.par!=-1)
    {
        addedge(rvtx.par,rvtx.vtx,rvtx.w,dg);
      ans[rvtx.vtx]=rvtx.wsf;
    }
    vis[rvtx.vtx]=true;
    for(Edge*e:graph[rvtx.vtx])
    {
        if(!vis[e->v])
        {
            que.push(dpair(e->v,rvtx.vtx,e->w,rvtx.wsf+e->w));
        }
    }

}
for(int i=0;i<ans.size();i++)
{
   cout<<ans[i]<<" ";
}
cout<<endl;
display(dg);

}
vector<int>low(n,0);
vector<int>dis(n,0);
vector<bool>appoints(n,false);
void dfs_ap(int src)
{
    
}



int main()
{
    constructg();
   // display();
   vector<bool>vis(7,false);
   ostringstream str1;
   str1<<0;
   string geek=str1.str();
   //haspath(0,6,vis," "+geek);
 //allpath(0,6,vis,""+geek,0);
// largepath(0,6,vis,""+geek,0);
// cout<<lpsf<<endl;
 //cout<<sf<<endl;
    // bsf(0,7,vis);
//bsf2(0,7,vis);
//cout<<hametonian(0,0,0,vis,""+geek);
vector<int>vis2(graph.size(),-1);
//isbipartite(0,vis2);
//tops(vis);
//khansalgo();
    return 0;
}
