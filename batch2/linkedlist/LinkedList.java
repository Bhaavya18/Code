import java.util.NoSuchElementException;
public class LinkedList{

private class Node 
{
    int data;
    Node next=null;
    Node(int data)
    this.data=data;

}  
private Node head=null;
private Node tail=null;
private int nodecount=0;
//basic functions//
public Node getNodeat(int idx)
{
    if(idx<0 || idx>=this.nodecount)
    throw new NullPointerException();

    Node curr=this.head;
    while((idx--)>=0)
    {
        curr=curr.next;
    }
    return curr;
}
//***************add *****/
private void addFirstNode()
private void addnodeAt(Node node ,int idx)
{
     if(idx==0)
     {
       node.next=head;
       this.head=node;
     }
     if(idx==this.nodecount)
     {
         this.tail.next=node;
         this.tail=node;
     }
    
    if(idx>0)
    Node prev=getNodeat(idx-1);
    if(idx<this.nodecount)
    Node succ=getNodeat(idx);

    prev.next=node;
    node.next=succ;

}
public void addAt(int idx,int data)
{
    Node node=new Node(data);
    addnodeAt(node,idx);
}
//********************remove */
private Node removeAtnode(int idx)
{  
    Node rn;
    if(idx==0)
    {  rn=this.head; 
      Node succ=getNodeat(idx+1);
      this.head=succ;
      rn.next=null;

      return rn.data;
    }
    if(idx==this.nodecount-1)
    {
         rn=this.tail;
        Node prev=getNodeat(idx-1);
        this.tail=prev;
        prev.next=null;
    }

    if(idx>0)
    Node prev=getNodeat(idx-1);

    if(idx<this.nodecount-1)
    Node succ=getNodeat(idx+1);

     rn=getNodeat(idx);
    rn.next=null;
    prev.next=succ;

   return rn;
}
public int removeAt(int idx)
{
   if(idx<0 || idx>=this.nodecount)
   throw new NullPointerException();
 
   return removeAtnode(idx).data;
}
}