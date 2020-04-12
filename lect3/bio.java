import java.util.Scanner;
public class bio{
 public static Scanner scn=new Scanner(System.in);
 public static void biotri(int n)
 {
     int r;
     int nst=1;
     for(r=0;r<=n;r++)
     {  int val=1;
         for(int cst=0;cst<=nst;cst++)
         {
             System.out.print(val);
             val=(val*(r-cst))/(cst+1);
         }
         System.out.println();
         nst++;
     }
 }
 public static void main(String [] arg)
 {
     System.out.print("enter n");
     int n=scn.nextInt();
     biotri(n);
 }

}