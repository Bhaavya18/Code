import java.util.Scanner;
public class questnum{
 public  static Scanner scn=new Scanner(System.in);
 public  static void main(String[] argv)
 {
     System.out.print("enter no of rows");
     int n=scn.nextInt();
     spacediamond(n);
     
 } 
 public static void spacediamond(int n)
 {
     int nsp=1;
     int nst=(n/2) +1;
     int r;
     for(r=1;r<=n;r++)
     { for(int cst=1;cst<=nst;cst++)
     {
         System.out.print("*");
     }
     for(int csp=1;csp<=nsp;csp++)
     {
      System.out.print(" ");
     }
     for(int cst=1;cst<=nst;cst++)
     {
        System.out.print("*"); 
     }
      System.out.println();
     if(r<=n/2)
     {
         nst--;
         nsp+=2;
     }
     else
     {
         nst++;
         nsp-=2;
     }


     }
 } 
}