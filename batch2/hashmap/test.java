import java.util.ArrayList;
import java.util.HashMap;
public class test{

   public static void main(String [] args)
   {
       // Hashmapop1();
      // Hashmapop3("aaaabbbbcc");
      int [] arr={1,1,1,2,2,3,3,3};
      int [] arr1={1,1,2,3,1,1};
      getcommonseries2(arr,arr1);
   } 
   
   public static void Hashmapop1()
   {
       HashMap<String,Integer>map=new HashMap<>();
       map.put("india",100);
       map.put("India",100);
       map.put("USA",200);
       map.put("UK",300);

       System.out.print(map);

   }

   public static void Hashmapop2(String str)
   {
       HashMap<Character,Integer> map=new HashMap<>();

       for(int i=0;i<str.length();i++)
       {
           char ch=str.charAt(i);

        //    if(!map.containsKey(ch))
        //    {
        //        map.put(ch,1);
        //    }
        //    else
        //    {
        //        map.put(ch,map.get(ch)+1);
        //    }

             map.put(ch,map.getOrDefault(map.get(ch),0)+1);  //getOrDefault(map.get(ch),0) if present then it returns value at key ch 
       }                                                      //otherwise returns default value which is 0 in this case;

       System.out.println(map);
   }


   public static void Hashmapop3(String str)
   {
       HashMap<Character,ArrayList<Integer>> map=new HashMap<>();

       for(int i=0;i<str.length();i++)
       {
           char ch=str.charAt(i);
           if(!map.containsKey(ch))   
           map.put(ch,new ArrayList<>());

           map.get(ch).add(i);  
       }

      for(char ch : map.keySet())
      {
          System.out.println( ch+"->"+map.get(ch));
      }

   }

   public static void getcommonseries(int[] one,int [] two)
   {
       HashMap<Integer,Boolean>map=new HashMap<>();
       
       for(int ele:one)
       {
           map.put(ele,true);  //distinct ele only taken by map
       }

       for(int ele:two)
       {
           if(map.containsKey(ele))
           {
               System.out.print(ele+" ");
               map.remove(ele);   //or we could also mark false
           }
       }
   }

   public static void getcommonseries2(int [] one,int [] two)
   {
       HashMap<Integer,Integer>map=new HashMap<>();
       for(int ele:one)
       {
           map.put(ele,map.getOrDefault(ele,0)+1);
       }
       
       for(int ele:two)
       {
           if(map.containsKey(ele))
           {
              System.out.print(ele+" ");

               if(map.get(ele)==1) 
               map.remove(ele);

               else
              map.put(ele, map.get(ele)-1);
           }
       }
   }

public static void frequency(String str)
{
    HashMap<String,int>map=new HashMap<>();
    for(int i=0;i<str.length();i++)
    {
        if(!map.containsKey(str[i]+""))
        map.put(str[i]+"",1);

        else
        {
            map.put(str[i]+"",map.get(str[i]+"")+1);
        }
    }
}




}