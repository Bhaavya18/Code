import java.util.Scanner;
public class prime23n{
 public static Scanner scn =new Scanner(System.in);
 public static void main(String[] args){
     System.out.println("enter no upto which prime no has to be printed");
     int n= scn.nextInt();
     int i,j;
     boolean flag=true;
     for(i=3;i<=n;i++)
     {
         for(j=2;j*j<=i;j++)
     {if(i%j==0)
     {flag =false;
     System.out.println(i);
     }
     }
     
     }     
}