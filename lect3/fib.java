import java.util.Scanner;
public class fib{
 public static Scanner scn=new Scanner(System.in);
 public static void fib(int n)
 {
     int a=0;
     int b=1;
     int c;
     int r;
     int nst=1;
     for(r=1;r<=n;r++)
     { for(int cst=1;cst<=nst;cst++)
        { System.out.print(a +" ");
         c=a+b;
         a=b;
         b=c;
        }
        System.out.println();
        nst++;
     }
 } 
 public static void main(String [] arg)
 {
     System.out.print("enter n");
     int n=scn.nextInt();
     fib(n);
 }  
}