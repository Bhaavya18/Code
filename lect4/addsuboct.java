import java.util.Scanner;
public class addsuboct{
public static Scanner scn=new Scanner(System.in);
public static int addoct(int n1,int n2)
{
   int rem;
   int pow=1;
   int res=0;
   int c=0;
   int sum;
   while(n1!=0 || n2!=0||c!=0)
   { rem=(n1%10 +n2%10) +c;
   c=(n1%10 +n2%10)/8;
   sum=rem%8;
   res+=sum*pow;
   pow*=10;
   n1=n1/10;
   n2=n2/10;

   } 
   return res;  
} 
public static int  suboct(int n1,int n2)
{
    boolean isneg=false;
    if(n1<n2)
    {
        int t;
        t=n1;
        n1=n2;
        n2=t;
        isneg=true;
    }
    int rem;
    int bor=0;
    int res=0;
    int pow=1;
    int c;
    while(n1 !=0)
    {
        rem=(n1%10 - n2%10) +bor;
        if(rem<0)
        {
             c=rem+8;
            bor=-1;  
        }
        else
        {
            c= rem;
            bor=0;
        }
        res =res +c*pow;
        pow*=10;
        n1=n1/10;
        n2=n2/10;
    }
    if(isneg)
     res*=-1;
     return res;
}
public static void main(String [] arg) 
{
    int n1=scn.nextInt();
    int n2=scn.nextInt();
    System.out.println( "add" +" " +addoct(n1,n2));
    System.out.print("sub" +" "+ suboct(n1,n2));
}  
}