import java.util.Scanner;
public class reverse{
    public static Scanner scn=new Scanner(System.in);
 public static void main(String[] arg)  
 { int[] arr=new int[]{6,7,3,8,9,2};
 reverse2(arr);
 display(arr);

 } 
 public static void swap(int[] a,int i,int j)
 { int t;
 t=a[i];
 a[i]=a[j];
 a[j]=t;

 }
 public static void reverse2(int[] a)
 {int si=0;
 int ei=a.length-1;
 while(si<=ei)
 {
     swap(a,si,ei);
     si++;
     ei--;
 }

 } 
 public static void display(int[] a)
 { for(int i=0;i<a.length;i++)
 {
     System.out.println(a[i]);
 }

 }
}