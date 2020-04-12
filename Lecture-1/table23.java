import java.util.Scanner;
public class table23{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args)
    { System.out.println("enter a number for table");
    int p= scn.nextInt();
    System.out.println("enter number upto which table has to be printed");
    int n= scn.nextInt();
    int i;
    for(i=1;i<=n;i++)
    {System.out.println(p*i);}

    }

}