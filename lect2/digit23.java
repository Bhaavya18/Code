import java.util.Scanner;
public class digit23{
    public static Scanner scn=new Scanner(System.in);
  public static void main(String[] args)
  {System.out.println("enter no");
  int n=scn.nextInt();
  int p=0;
  while(n!=0)
  {n=n/10;
  p++;
  }
  System.out.println(p);
  }  
}