import java.util.Scanner;
public class power2
{
  public static Scanner scn=new Scanner(System.in);
  public static void main(String[] arg)
  {
      int n=scn.nextInt();
      int p=scn.nextInt();
      int t=power34(n,p);
      System.out.print(t);
  }  
  public static int power23(int n,int p)
  {
      if(p==0)
      {
          return 1;
      }
      int res=power23(n,p-1);
      
      return res*n; 
  }
  public static int power34(int a,int b)
  { 
    if(b==0)
    {
        return 1;
    }
    int res=power34(a,b/2);
    if(b%2==0)
    {
        return res*res;
    }
    else
    {
        return res*res*a;
    }



  }
}