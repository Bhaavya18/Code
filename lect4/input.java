import java.util.Scanner;
public class input{
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
         System.out.print(a[i]+" ");

     }
 }
 public static void main(String [] arg)
 {
     int n=scn.nextInt();
     int [] a=new int[n];
     input(a);
     display(a);
 }

}