import java.util.ArrayList;
import java.util.Stack;
public class tree{
public static class Node
{
    int data=0;
    Node left=null;
    Node right=null;
    public Node(){

    }
    public Node(int data)
    {
        this.data=data;
    }

}
 static int idx=0;
public static  Node nodecreate(int [] arr)
{
    if(idx==arr.length-1 || arr[idx]==-1)
    {
        idx++;
        return null;
    }
    Node node=new Node(arr[idx]);
    idx++;
    node.left=nodecreate(arr);
    node.right=nodecreate(arr);
    return node;
}
public static void display(Node node)
{
    if(node==null)
      return;
      System.out.print(node.left!=null?node.left.data:".");
      System.out.print("->"+node.data+"<-");
      System.out.print(node.right!=null?node.right.data:".");
      System.out.println();
      display(node.left);
      display(node.right);
}
public static  int maxi(Node node)
{
    if(node==null)
    return Integer.MIN_VALUE;    //for min value of integer
    int lrmc=maxi(node.left);
    int rmc=maxi(node.right);
    int res1=Math.max(lrmc,rmc);
    int res2=Math.max(node.data,res1);
    return res2;
}
public static int size(Node node)
{
    if(node==null)
    return 0;
    int left=size(node.left);
    int right=size(node.right);
    return (left+right)+1;
}
public static boolean find(Node node,int data)
{
    if(node==null)
    return false;
    if(node.data==data)
    return true;
    boolean res=false;
     res=res||find(node.left,data);
     res=res||find(node.right,data); //if we encounter data once no further calling if will return true true and so on
     return res;
}
public static int height(Node node)
{
    if(node==null)
    return -1;
    int left=height(node.left);
    int right=height(node.right);
    return Math.max(left,right)+1;   //to find height of tree
}
public static void main(String[] args)
{
    int [] arr={10,20,30,40,-1,-1,50,-1,-1,60,-1,70,-1,-1,80,90,100,120,-1,-1,130,-1,-1,110,-1,-1,140,-1,-1};
    Node root=nodecreate(arr);
   // display(root);
  // System.out.print(maxi(root));
 // System.out.print(size(root));
 //System.out.print(find(root,80));
 
// System.out.print(height(root));
//  ArrayList<Node>ans=roottonode(root,40);
//  for(Node node_:ans)
//  {
//      System.out.print(node_.data+",");
//  }
// System.out.print(lca(root,40,80));
//ystem.out.print(dia1(root));
//int [] ans=dia2(root);
//System.out.print(ans[0]);
//ia3(root);
//System.out.print(maxdia);
//leaftoleaf(root);
//System.out.print(maxsum);
//nodetonode(root);
//System.out.print(mincamera2(root));
//bst();
 int [] a=new int[10];
    for(int i=0;i<10;i++)
    {
        a[i]=(i+1)*10;
    }
    Node root2=bstcreate(a,0,9);
//System.out.print(findb(root2,40)); 
//System.out.print(findi(root2,40));
Node root3=adddata(root2,25);
//display(root3);
//System.out.print(maxtree(root2));
//Node root4=removedata(root2,20);
//display(root4);
preorder(root2);


}
public static ArrayList<Node> roottonode(Node node,int data)
{
    if(node==null)
    {
        return new ArrayList<>();
    }
    if(node.data==data)
    {
        ArrayList<Node>base=new ArrayList<>();
        base.add(node);
        return base;
    }
    ArrayList<Node>left=roottonode(node.left,data);
    if(left.size()!=0)
    {
        left.add(node);
        return left;
    }
    ArrayList<Node>right=roottonode(node.right,data);
    if(right.size()!=0)
    {
         right.add(node);
         return right;
    }
    return new ArrayList<>();

}
public static int lca(Node node,int data1,int data2)
{
    
    ArrayList<Node>list1=roottonode(node,data1);
    ArrayList<Node>list2=roottonode(node,data2);
    int i=list1.size()-1;
    int j=list2.size()-1;
    int ans=-1;
    while(i>=0&&j>=0)
    {
        if(list1.get(i)!=list2.get(j))
        break;
        ans=list1.get(i).data;
        i--;
        j--;
    }
    return ans;
}
public static void kdown(Node node,Node pnode,int level)
{
    if(node==null || pnode==node)
    return;
    if(level==0)
    System.out.print(node.data+" ");
    kdown(node,pnode,level-1);
}
public static void kaway(Node node,Node pnode,int level,int data)
{
    ArrayList<Node>list=roottonode(node,data);
    pnode=null;
    for(int i=0;i<list.size();i++)
    {
        kdown(list.get(i),pnode,level-i);
        pnode=list.get(i);
    }
}
public static int dia1(Node node)
{
    if(node==null)
    {
        return 0;
    }
    int ld=dia1(node.left);
    int rd=dia1(node.right);
    int lh=height(node.left);
    int rh=height(node.right);
    return Math.max(Math.max(ld,rd),lh+rh+2);
}
public static int [] dia2(Node node)
{
    if(node==null)
    {
        int [] base={0,-1};
        return base;
    }
    int [] ld=dia2(node.left);
    int [] rd=dia2(node.right);
    int [] ans=new int[2];
    ans[0]=Math.max(Math.max(ld[0],rd[0]),ld[1]+rd[1]+2);
    ans[1]=Math.max(ld[1],rd[1])+1;
    return ans;
}
static int maxdia=0;
public static int dia3(Node node)
{
    if(node==null)
    return -1;
    int lh=dia3(node.left);
    int rh=dia3(node.right);
    maxdia=Math.max(maxdia,lh+rh+2);
    return Math.max(lh,rh)+1;

}
static int maxsum=Integer.MIN_VALUE;
public static int leaftoleaf(Node node)      //leetcode
{
    if(node==null)
    return Integer.MIN_VALUE;
    if(node.left==null && node.right==null)
    return node.data;
    int lmaxsum=leaftoleaf(node.left);
    int rmaxsum=leaftoleaf(node.right);
    if(node.left!=null && node.right!=null)
    {
      maxsum=Math.max(maxsum,lmaxsum+rmaxsum+node.data);
    }
    return Math.max(lmaxsum,rmaxsum)+node.data;
}
static int maxsum2=Integer.MIN_VALUE;
public static int nodetonode(Node node)
{
    if(node ==null)
    return 0;
    int lmaxsum=nodetonode(node.left);
    int rmaxsum=nodetonode(node.right);
    int maxbranch=Math.max(lmaxsum,rmaxsum);
    maxsum2=Math.max(Math.max(maxsum2,node.data),Math.max(maxbranch+node.data,lmaxsum+rmaxsum+node.data));
    return Math.max(maxbranch+node.data,node.data);
}    
//-1  i need a camera
//0   i am already covered
//1   i am a camera
static int camera=0; 
public static int mincameras(Node node)
{
    if(node==null)
    return 0;
    int left=mincameras(node.left);
    int right=mincameras(node.right);
    if(left==-1 ||right==-1)
    {
        camera++;
        return 1;
    }
    if(left==1 || right==1)
    {
        return 0;
    }
    return -1;

}  
public static int  mincamera2(Node node)
{
    int val=mincameras(node);   //root is uncovered test case
    if(val==-1)
    {
        camera++;     
    }
    return camera;
}   
//**************************************************************************************************************** */
public static Node bstcreate(int [] arr,int si,int ei) 
{
    if(si>ei)
    return null;
    int mid=(si+ei)>>1; //int mid=si+ (ei-si)/2
    Node node =new Node(arr[mid]);
    node.left=bstcreate(arr,si,mid-1);
    node.right=bstcreate(arr,mid+1,ei);
    return node;
}  
public static void bst()
{
    int [] arr=new int[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=(i+1)*10;
    }
    Node root=bstcreate(arr,0,9);
    display(root);
} 
public static boolean findb(Node node,int data)
{
    if(node==null)
    return false;

    else if(node.data==data)
    return true;

    else if(data<node.data)
    return findb(node.left,data);

    else
    return findb(node.right,data);

}   
public static boolean findi(Node node,int data)
{
    while(node!=null)
    {
        if(data==node.data)
        return true;
        else if(node.data>data)
        node=node.left;
        else
        node=node.right;
    }
    return false;
}
public static Node adddata(Node node,int data)
{
    if(node==null)
    return new Node(data);
    if(data>node.data)
    node.right=adddata(node.right,data);
    else
    node.left=adddata(node.left,data);
    return node;
}
public static class pair{
    int height=-1;
    int size=0;
    boolean find=false;
    Node succ=null;
    Node pred=null;
    Node prev=null;
    int ceil=Integer.MAX_VALUE;
    int floor=Integer.MIN_VALUE;
}
public static int maxtree(Node node)
{
    if(node==null)
    return Integer.MIN_VALUE;
    Node rnode=node;
    while(rnode.right!=null)
    {
        rnode=rnode.right;
    }
    return rnode.data;
}
public static int mintree(Node node)
{
    if(node==null)
    return Integer.MAX_VALUE;
    Node rnode=node;
    while(rnode.left!=null)
    {
        rnode=rnode.left;
    }
    return rnode.data;
}
public static Node removedata(Node node,int data)
{
    if(node==null)
    return null;
    if(node.data==data)
    {
        if(node.left==null || node.right==null)
        {
            return (node.left==null?node.right:node.left);
        }
        else
        {
            int maxdata=maxtree(node.left);
            node.data=maxdata;
            node.left=removedata(node.left, maxdata);
      
        }
   }
   else if(data>node.data)
   {
       node.right=removedata(node.right,data);
   }
   else
   {
       node.left=removedata(node.left,data);
   }
   return node;
}
// public static Node rightmost(Node leftnode,Node cur)
// {
//     while(leftnode.right!=null && leftnode.right!=cur)
//     {
//         leftnode=leftnode.right;
//     }
//     return leftnode;

// }
// public static void morris(Node node)
// {
//     Node cur=node;
//     while(cur!=null)
//     {
//         Node nex=cur.left;
//         if(nex.left==null)
//         {
//             System.out.print(cur.data+" ");
//         }
//     }
// }
public static class tpair
{
    Node node;
    boolean sd=false;
    boolean rd=false;
    boolean ld=false;
    tpair(Node node)
    {
        this.node=node;
    }
}
public static void preorder(Node node)
{
    Stack<tpair>st=new Stack<>();
    st.add(new tpair(node));
    while(st.size()!=0)
    {
        tpair tnode=st.peek();
        if(!tnode.sd)                            //if sd is written in between in
                                                //if sd is written at last post order after rd and ld
        {
            tnode.sd=true;
            System.out.print(tnode.node.data+" ");
        }
        else if(!tnode.ld)
        {
            tnode.ld=true;
            if(tnode.node.left!=null)
            st.add(new tpair(tnode.node.left));
        }
        else if(!tnode.rd)
        {
            tnode.rd=true;
            if(tnode.node.right!=null)
            st.add(new tpair(tnode.node.right));
        }
        else{
            st.pop();
        }
    }
    
}


}