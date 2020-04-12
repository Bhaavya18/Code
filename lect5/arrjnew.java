import java.util.Scanner;
public class arrjnew{
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
         System.out.print(a[i] +" ");
     }
 }  
 public static boolean find(int []a,int data)
 { for(int i=0;i<a.length;i++)
 {
     if(a[i]==data)
     {
         return true;
     }
 }
  return false;   
 }
 public static void swap(int [] a,int si,int ei)
 {
     int t;
     t=a[si];
     a[si]=a[ei];
     a[ei]=t;
 }
 public static void reverse(int [] a,int si,int ei)
 {
     while(si<=ei)
     {
         swap(a,si,ei);
         si++;
         ei--;
     }
 }
 public static void srotate(int [] a,int r)
 {r=r%a.length;
 r=r<0?r+a.length:r;
 reverse(a,0,r-1);
 reverse(a,r,a.length-1);
 reverse(a,0,a.length-1);
 display(a);
   
 }
 public static void main(String [] arg)
 {
     int n=scn.nextInt();
     int[] a=new int [n];
     input(a);
   //  int data=scn.nextInt();
    //System.out.print(find(a,data));
    int r=scn.nextInt();
    srotate(a,r);

 }
}