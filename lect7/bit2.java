import java.util.Scanner;
public class bit2
{
    public static Scanner scn=new Scanner(System.in);
    public static void main(String[] argv)
    { System.out.print("enter no");
    int n=scn.nextInt();
    onkbit(n);
    System.out.print(n);

    }
   public static void onkbit(int n)
   { for(int i=0;i<32;i++)
        {int mask=1;
        mask<<=i;
        if((8n & mask)==0)
       {n|=mask;}
       }
    }
}
