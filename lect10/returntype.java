import java.util.ArrayList;
import java.util.Scanner;
public class returntype{
public static ArrayList<String> sub(String str)
{ if(str.length()==0)
{
    ArrayList<String> base=new ArrayList<>();
    base.add(" ");
    return base;
}

char ch=str.charAt(0); //to access character at 0th position of the substring
String ros=str.substring(1); //all characters except 0th position
ArrayList<String> recans=sub(ros);
ArrayList<String> myans=new ArrayList<>();

//myans.addall(recans);
for(String s:recans)
{
    myans.add(s);
}
for(String s:recans)
{
    myans.add(ch+s);//in recans only we are adding characters
}
return myans;
}
public static void main(String[] args)
{
    String str="abcd";
    System.out.println(sub(str));
}






}