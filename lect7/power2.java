import java.util.Scanner;
public class power2{
public static Scanner scn=new Scanner(System.in);
public static void main(String[] arg)
{
    System.out.print("enter no");
    int n=scn.nextInt();
   boolean t= power2y(n);
   System.out.print(t);
}
public static boolean power2y(int n)
{
    if((n &(n-1))==0)
    {
        return true;
    }
    return false;
}
}