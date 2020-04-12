import java.util.Scanner;
public class ifelse{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] args){
      System.out.print("enter a");
       int a=scn.nextInt();
System.out.println();

System.out.print("enter b");
       int b=scn.nextInt();
       System.out.println();

       System.out.print("enter c");
       int c=scn.nextInt();
       System.out.println();
       if(a>b && a>c)
       {System.out.println(a);
       }
       else if(b>c && b>a)
       {System.out.println(b);}
       else
       {System.out.println(c);} 
    }
}