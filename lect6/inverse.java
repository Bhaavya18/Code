import java.util.Scanner;
public class inverse{
 public static Scanner scn=new Scanner(System.in);
 public static void input(int [] a)
 {
     for(int i=0;i<a.length;i++)
     {
         a[i]=scn.nextInt();
     }
 } 
  public static void display(int [] a)
 {
     for(int i=0;i<a.length;i++)
     {
         System.out.print(a[i]);
     }
 } 
 
 public static boolean checkin(int [] a,int []b)
 {
     int []c=new int[a.length];
     for(int i=0;i<a.length;i++)
     {
         c[a[i]]=i;
     }
     int flag=0;
     for(int i=0;i<b.length;i++)
     {
         if(c[i]!=b[i])
         flag=1;
     } 
     if(flag==0)
     return true;
     else
     return false;
 }
 public static void main(String [] arg)
 {
     int n=scn.nextInt();
     int []a=new int[n];
     int []b=new int[n];
     input(a);
     input(b);
     int flag=0;
     for(int i=0;i<a.length;i++)
     {
         if(a[i]>=a.length || a[i]<0)
         flag=1;
     }
     if(flag==0)
     {
         System.out.print(checkin(a,b));
     }
 
}
}