import java.util.ArrayList;
public class clientserver{

 public static void main(String[] args)
 {
     HashMap_<String,Integer> map=new HashMap_<>();

    // System.out.print(map);
   // map.put(10,20);
//    map.put(13,30);
//    map.put(3,40);
//    map.put(23,90);
//     map.put(43,10);
  // System.out.print(map);
  //ArrayList<Integer>ans=new ArrayList<>();
  //ans=map.keyset();
//   for(int i=0;i<ans.size();i++)
//   {
//       System.out.print(ans.get(i)+" ");
//   }
  //  System.out.print(map.containskey(10));
 // System.out.print(map.getordefault(53,0));
 map.put("abc",10);
 map.put("gfh",20);
 map.put("cdef",30);
 System.out.print(map.getordefault("gpm",9));

 } 

}