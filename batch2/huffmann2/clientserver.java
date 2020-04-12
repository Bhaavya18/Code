public class clientserver{

    public static void main(String[] args)
    {
        huffmannED hd=new huffmannED("aaaabbbbccccddddyyyjjjeeeafffhhiikkklllmmnno");
        String s=hd.encoding("abcjfhy");
         String s1=hd.decoding(s);
        // System.out.print(s1);
         System.out.print(s1+"->"+s);
    }
}