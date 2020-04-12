import java.util.PriorityQueue;
import java.util.HashMap;

public class huffmanned{

   private  HashMap<String,String>encode=new HashMap<>();
   private  HashMap<String,String>decode=new HashMap<>();

    private class Node implements Comparable <Node>{
      String data="";
      int freq=0;
      Node left=null;
      Node right=null;
      
      Node(String data,int freq,Node left,Node right)
      {
          this.data=data;
          this.freq=freq;
          this.left=left;
          this.right=right;
      }

    @Override
    public int compareTo(Node o)
    {
        return this.freq-o.freq;
    }

  } 
 

public huffmanned(String str)
{
    frequencyMap(str);
}  

private void frequencyMap(String str)
{
   // int count=0;
   int [] frequency =new int [26];

   for(int i=0;i<str.length();i++)
   {
       frequency[str.charAt(i)-'a']+=1;
   }

   PriorityQueue<Node>pq=new PriorityQueue<>();

   for(int i=0;i<frequency.length;i++)
   {
       if(frequency[i]>0)
     {  Node np=new Node((char)(i+'a')+" ",frequency[i],null,null);
        pq.add(np);
     }

   }

  while (pq.size()!=1)
  {
      Node node1=pq.poll();
      Node node2=pq.poll();

      Node merge=new Node(" ",node1.freq+node2.freq,node1,node2);

      pq.add(merge);
  }

  Node root=pq.poll();
  traversal(root," ");
  
}

private void traversal(Node root,String code)
{
    if(root.left==null && root.right==null)
    {
        encode.put(root.data,code);
        decode.put(code,root.data);
        return;
    }

    traversal(root.left,code+"0");
    traversal(root.right,code+"1");
}

public String encodestring(String str)
{
    StringBuilder sb=new StringBuilder();

    for(int i=0;i<str.length();i++)
    {
        String s=str.charAt(i)+"";
        sb.append(encode.get(s));
    }

    return sb.toString();
}

public String decodestring(String str)
{
    StringBuilder sb=new StringBuilder();
     int i=0;
     for(int j=1;j<=str.length();j++)
     {
         String s=str.substring(i,j);
         if(decode.containsKey(s))
         {
             sb.append(decode.get(s));
             i=j;
         }
     }

   return sb.toString();    

}


}