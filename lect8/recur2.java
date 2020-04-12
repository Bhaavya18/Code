import java.util.Scanner;
public class recur2{
 public static Scanner scn=new Scanner(System.in);
 public static int factorial(int n)
 { 
     if(n==1)
     {
         return 1;
     }
  int res= factorial(n-1);
  return res*n;
 } 
 public static  int power(int a,int b)
 {
     if(b==1)
     {return a;}
     int res=power(a,b-1);
     return res*a;
 }
 public static int power2(int a,int b)
 {
     if(b==1)
     return a;
     int res=power2(a,(b/2));
     if(b%2==0)
     {
         return res*res;
     }
     else
     {
         return res*res*a;
     }
 }
 public static void main(String [] arg)
 {
     int n=scn.nextInt();
     int b=scn.nextInt();
    // System.out.print(factorial(n));
    //System.out.print(power(n,b));
System.out.print(power2(n,b));
 }  
}