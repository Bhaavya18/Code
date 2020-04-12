import java.util.Scanner;
public class reverse23{
 public static Scanner scn =new Scanner(System.in);
 public static void main(String[] args) 
 {System.out.println("enter number");
 int n=scn.nextInt();
 int c,p=0;
 while(n!=0)
 {c=n%10;
 p=p*10+c;
 n=n/10;}
 System.out.println(p);
 }  
}