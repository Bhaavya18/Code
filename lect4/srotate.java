import java.util.Scanner;
public class srotate{
 public static Scanner scn=new Scanner(System.in);
 public static void main(String[] argv )
 { int [] arr=new int[]{1,2,3,4,5,6};
 rotate2(arr,2);
 display(arr);
 }
 public static void swap(int[] a,int i,int j)
 { int t;
 t=a[i];
 a[i]=a[j];
 a[j]=t;

 }
 public static void rotate2(int []a,int r)
 { r=r%a.length;
 r=r<0?r+a.length:r;
 int si=0;
 int ei=r-1;
 while(si<=ei)
 {swap(a,si,ei);
 si++;
 ei--;}
 int p=r;
 int q=a.length-1;
 while(p<=q)
 {
    swap(a,p,q);
    p++;
    q--; 
 }
 int x=0;
 int y=a.length-1;
 while(x<=y)
 {
     swap(a,x,y);
     x++;
     y--;
 }
 }
     
 public static void display(int[] a )
 {
     for(int i=0;i<a.length;i++)
     {
         System.out.println(a[i]);
     }
 }
   








}