import java.util.Scanner ;
public class rotate{
    public static Scanner scn=new  Scanner(System.in);

    public static void main(String[] args)
{ System.out.println("enter n");
int n= scn.nextInt();
System.out.println("enter no of rotations");
int r=scn.nextInt();
System.out.println(rotation(n,r));
}
    public static int noOfDigit(int n)
    { int p=0;
    while(n!=0)
    {n=n/10;
    p++;}
    return p;

    }
    public static int rotation(int n,int r)
    {int digit=noOfDigit(n);
    r%=digit;
    r=r<0?r+digit:r;
    int div=1;
    int mul=1;
    for(int i=1;i<=digit;i++)
    {if(i<=r)
    mul*=10;
    else
    div*=10;
    }
    int rem=n%div;
    n=n/div;
    return (rem*mul +n);

    }

}