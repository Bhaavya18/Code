import java.util.*;
import java.util.ArrayList;
import java.util.LinkedList;
public class avl{
public static class Node
{
    int data=0;
    Node left=null;
    Node right=null;

    int height=-1;
    int bal=0;
    public Node(){

    }
    public Node(int data)
    {
        this.data=data;
    }

}
// public static Node bstcreate(int [] arr,int si,int ei) 
// {
//     if(si>ei)
//     return null;
//     int mid=(si+ei)>>1; //int mid=si+ (ei-si)/2
//     Node node =new Node(arr[mid]);
//     node.left=bstcreate(arr,si,mid-1);
//     node.right=bstcreate(arr,mid+1,ei);
//     return node;
// }  
// public static void bst()
// {
//     int [] arr=new int[10];
//     for(int i=0;i<10;i++)
//     {
//         arr[i]=(i+1)*10;
//     }
//     Node root=bstcreate(arr,0,9);
//     //display(root);
// } 
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
public static Node adddata(Node node,int data)
{
    if(node==null)
    return new Node(data);

    if(data<node.data)
    node.left=adddata(node.left,data);
    
    else
    node.right=adddata(node.right,data);

    node=rotation(node);
    return node;
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
// public static int mintree(Node node)
// {
//     if(node==null)
//     return Integer.MAX_VALUE;
//     Node rnode=node;
//     while(rnode.left!=null)
//     {
//         rnode=rnode.left;
//     }
//     return rnode.data;
// }
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
            int maxdata=maxtree(node.left);
            node.data=maxdata;
            node.left=removedata(node.left, maxdata);
        
        
   }
   else if(data>node.data)
   {
       node.right=removedata(node.right,data);
   }
   else
   {
       node.left=removedata(node.left,data);
   }
   node=rotation(node);
   return node;
}
public static Node ll(Node node)
{
    Node y=node.left;
    Node yright=y.right;

    y.right=node;
    node.left=yright;

    updatebalheight(node);
    updatebalheight(y);
    return y;
}
public static Node rr(Node node)
{
    Node y = node.right;
    Node yleft=y.left;

    y.left=node;
    node.right=yleft;

    updatebalheight(node);
    updatebalheight(y);
    return y;
}
public static Node rotation(Node node)
{
    updatebalheight(node);
    if(node.bal==2)
    {
        if(node.left.bal==1)
        {
            return ll(node);
        }
        else
        {
            node.left = rr(node.left);
            return ll(node);

        }
    }
     if(node.bal==-2)
    {
        if(node.right.bal==-1)
        {
            return rr(node);
        }
        else
        {
           node.right = ll(node.right);
           return rr(node);
        }
    }
    return node;
}
public static void updatebalheight(Node node)
{
    int lh=-1;
    int rh=-1;
    if(node.left!=null)
    lh=node.left.height;

    if(node.right!=null)
    rh=node.right.height;

    node.height=Math.max(lh,rh)+1;
    node.bal=lh-rh;
}
public static void lcabst(Node node,int d1,int d2)
{
    int lca=0;
    if(d1>node.data)
   lcabst(node.right,d1,d2);

    else if(d2<node.data)
   lcabst(node.left,d1,d2);

    else
    {
       System.out.print(node.data);
       return;
    }

}
// public static void printinorder(Node node)
// {
//     Stack<Node>st=new Stack<>();
//     st.add(node);
//     while(st.size()!=0)
//     {
//         Node tops=st.peek();
//         if(tops.left!=null)
//         {
//             st.add( tops.left);
//         }

//         else if(tops.right!=null)
//         {
//             System.out.print(tops.data+" ");
//             Node rnode=tops;
//             st.pop();
//             st.add(rnode.right);
//         }

//         else
//         {
//             System.out.print(tops.data+" ");
//             st.pop();
//         }

//     }
    
// }
static int leftmost=-1;
static int rightmost=-1;

public static void width(Node node,int level)
{
    if(node==null){
        return;
    }
    
        leftmost=Math.min(leftmost,level);
        rightmost=Math.max(rightmost,level);
    

    width(node.left,level-1);
    width(node.right,level+1);

}

public static void verticalorder(Node node)
{
    LinkedList<Node>que1=new LinkedList<>();
    LinkedList<Integer>que2=new LinkedList<>();
    width(node,0);
    ArrayList<Integer>[]list=new ArrayList<Integer>()[rightmost-leftmost];
    
    que1.addLast(node);
    que2.addLast(-leftmost);

    while(que1.size()!=0)
    {
        int size=que1.size();
        while(size-->0)
        {
            Node rn=que1.removeFirst();
            int rd=que2.removeFirst();

            if(rn.left!=null)
            {
                que1.addLast(rn.left);
                que2.addLast(rd-1);
            }

            if(rn.right!=null)
            {
                que1.addLast(rn.right);
                que2.addLast(rd+1);
            }
            list[rd].add(rn.data);

        }
    }

    for(int i=0;i<=(rightmost-leftmost);i++)
    {
        for(int j=0;j<list[i].size();j++)
        {
            System.out.print(list[i].get(j)+" ");
        }
        System.out.println();
    }

}
public static void main(String[]args)
{
  Node root=null;
    for(int i=1;i<=20;i++)
    {
        root=adddata(root,i*10);
    }
    //Node root=bstcreate(a,0,19);
    //Node root2=rotation(root);
  // display(root);
  //lcabst(root,40,120);
   //Node root2=adddata(root,80);
  // printinorder(root);
//   verticalorder(root);

}


}