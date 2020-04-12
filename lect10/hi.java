import java.util.Scanner;
public class hi{
public static Scanner scn=new Scanner(System.in);    
public static String removehi(String ques)
{
    if(ques.length()==0)
    {
        return " ";
    }
   if(ques.length()>1 && ques.substring(0,2).equals("hi"))
    {
        return removehi(ques.substring(2));
    }
    else
    {
        char ch=ques.charAt(0);
        return removehi(ch+ques.substring(1));
    }
}
public static void main(String[] arg)
{  System.out.print("enter string");
   String str=scn.nextLine();
   System.out.print(removehi(str));
}




}