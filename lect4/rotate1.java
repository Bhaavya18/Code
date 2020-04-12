import java.util.Scanner;
public class rotate1
{ public static Scanner scn= new Scanner(System.in);
public static void input(int[] arr)
{
   for(int i=0;i<arr.length;i++)
   { System.out.println("enter no");
   int no=scn.nextInt();

   } 
}
public static void display(int[] arr)
{ int i;
for(i=0;i<arr.length;i++)
{
    System.out.print(arr[i]);
    System.out.print(" ");
}

}
public static void rotate(int[] arr, int r)
{ r%=arr.length;
r=r<0?r+arr.length:r;
int [] ans =new int[arr.length];
int k=0;
int i;
for( i=r;i<arr.length;i++)
{ ans[k]=arr[i];
 k++;
}
for(i=0;i<r;i++)
{
    ans[k]=arr[i];
    k++;
}
display(ans);
}
public static void main(String [] argv)
{ int [] arr=new int[5];
input(arr);
System.out.println("enter no of rotations");
int r=scn.nextInt();
rotate(arr,r);

}

}