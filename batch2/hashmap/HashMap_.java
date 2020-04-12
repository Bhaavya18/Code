import java.util.LinkedList;
import java.util.ArrayList;
public class HashMap_<k,v>{    //to make hashmap generic

public class Node{
      k key;
      v value;

 public Node(k key,v value)
 {
     this.key=key;
     this.value=value;
 }

@Override
 public String toString()
 {
     return this.key+"="+this.value;
 }

}

private int size=0;
private LinkedList<Node>[] buckets=new LinkedList[10];

public int myhashcode(k key)
{
    int val=key.hashCode();
    return Math.abs(val);
}

public int mygroup(k key)
{
    return myhashcode(key)%buckets.length;
}

public HashMap_()
{
    reassign();

}

public void reassign()
{
    for(int i=0;i<buckets.length;i++)
    {
        buckets[i]=new LinkedList<>();     //we can do this or in put function also if(group==null)
                                                                                // {buckets[code]=new LinkedList<>();}
    }
    this.size=0;  //we are doing size 0 because when rehash is called then everything will be regrouped and added to group
}



@Override
public String toString()
{
    StringBuilder sb=new StringBuilder();
    sb.append("{");
    for(int i=0;i<buckets.length;i++)
    {
        if(buckets[i].size()>0)
     {   LinkedList<Node>group=buckets[i];
        int size=group.size();
        while(size-->0)
        {
            Node tnode=group.getFirst();
            sb.append(tnode+",");       //we had already override toString() function in class
            group.addLast(group.removeFirst());
        }

     } 
    }
   sb.deleteCharAt(sb.length()-1);
   sb.append("}");

    return sb.toString();
}

public void put(k key,v value)
{
    int code=mygroup(key);
    LinkedList<Node>group=buckets[code];
    // if(group==null)
    // {
    //     buckets[code]=new LinkedList<>();
    // }
    Node rn=foundingroup(group,key);
    if(rn!=null)
    rn.value=value;

    else
    {
        Node node=new Node(key,value);
        group.addLast(node);

        double lambda=group.size()*1.0/buckets.length;

         if(lambda>=3.0)
         {
            rehash();
         }
    }
      
   // System.out.print(group);
}


public void rehash()
{
    LinkedList<Node>[] oldbuckets=buckets;
    buckets=new LinkedList[oldbuckets.length*2];
    reassign();

    for(int i=0;i<oldbuckets.length;i++)
    {
        if(oldbuckets[i].size()>0)
        {
            LinkedList<Node>group=oldbuckets[i];
            int size=group.size();
            while(size-->0)
            {
                Node tnode=group.removeFirst();
                put(tnode.key,tnode.value);
            }
        }
    }
}


public boolean containskey(k key)
{
    int code=mygroup(key);
    LinkedList<Node>group=buckets[code];
    Node rn=foundingroup(group,key);

    return rn!=null ?true:false;
}

public ArrayList<k> keyset()
{
    ArrayList<k>ans=new ArrayList<>();
    
     for(int i=0;i<buckets.length;i++)
     {
         if(buckets[i].size()>0)
       {
           LinkedList<Node>group=buckets[i];
           int size=group.size();

           while(size-->0)
           {
               Node tnode=group.getFirst();
               ans.add(tnode.key);

               group.addLast(group.removeFirst());

           }
       }
    }

    return ans;
}

public v getordefault(k key,v defaultvalue)
{
    int code=mygroup(key);
    LinkedList<Node>group=buckets[code];
    Node rn=foundingroup(group,key);

    return rn!=null?rn.value:defaultvalue;
}

public Node remove(k key)
{
    int code=mygroup(key);
    LinkedList<Node>group=buckets[code];
    Node rn=foundingroup(group,key);

    if(rn!=null)
    {
        this.size--;
    }

   else
   {
     System.out.print("element not found");
   }
  
  return rn==null?null:group.removeFirst();

}

public v get_(k key)
{
    int code=mygroup(key);
    LinkedList<Node>group=buckets[code];
    Node rn=foundingroup(group,key);
    return rn==null?null:rn.value;

}


public Node foundingroup(LinkedList<Node>group,k key)
{  
    if(group==null)
    return null;

    int size=group.size();
    Node rn=null;

    while(size-->0)
    {
        Node tnode=group.getFirst();

        if(tnode.key==key)
        {
           rn=tnode;
           break;
        }

        group.addLast(group.removeFirst());
    }
   
   return rn;
}

public int size_()
{
    return this.size;
}

public boolean isempty()
{
    return this.size==0;
}

}