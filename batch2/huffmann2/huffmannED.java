import java.util.PriorityQueue;
import java.util.HashMap;
public class huffmannED{

private HashMap<String,String>encode=new HashMap<>();
private HashMap<String,String>decode=new HashMap<>();

private class Node implements Comparable<Node>{
    String data="";
    int freq=0;
    Node left=null;
    Node right=null;

    public Node(String data,int freq,Node left,Node right)
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

private void huffmanntree(String str)
{
    int [] freqmap= new int [26];

    for(int i=0;i<str.length();i++)
    {
        freqmap[str.charAt(i)-'a']++;
    }

     PriorityQueue<Node>pq=new PriorityQueue<>();

    for(int i=0;i<freqmap.length;i++)
    {
        if(freqmap[i]>0)
        {
           pq.add(new Node((char)(i+'a')+"",freqmap[i],null,null));
        }
    }

    while(pq.size()!=1)
    {
        Node node1=pq.poll();
        Node node2=pq.poll();

        pq.add(new Node("",node1.freq+node2.freq,node1,node2));
    }

    Node root=pq.poll();
    huffmanntraversal(root,"");
}

private void huffmanntraversal(Node root,String code )
{
    if(root.left==null && root.right==null)
    {
        encode.put(root.data,code);
        decode.put(code,root.data);
        return;
    }

    huffmanntraversal(root.left,code+"0");
    huffmanntraversal(root.right,code+"1");
}

public huffmannED(String str)
{
    huffmanntree(str);
}

public String encoding(String str)
{
    StringBuilder sb=new StringBuilder();

    for(int i=0;i<str.length();i++)
    {
        String s=str.charAt(i)+"";
        sb.append(encode.get(s));
    }

    return sb.toString();
}

public String decoding(String str)
{
     int i=0;
     StringBuilder sb=new StringBuilder();
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


    // int st=0;
    // int en=1;
    // while( en<=str.length())
    // {
    //     String s=str.substring(st,en);

    //     if(decode.containsKey(s))
    //     {
    //        sb.append(decode.get(s));
    //        en++;
    //        st=en;
    //     }

    //     else
    //     {
    //         en++;
    //     }
    // }

    // return sb.toString();
}

}