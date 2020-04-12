import java .util.Scanner;
public class sumj{
    public static Scanner scn =new Scanner(System.in);
    public static void main(String[] arg)
    { System.out.println("row");
        int n=scn.nextInt();
        System.out.println("column");
        int m=scn.nextInt();
        int [][] a=new int[m][n];
        int [][] b=new int[m][n];
        input(a);
        input(b);
        sum(a,b);


    }
    public static void input(int [][] a)
    {
        for(int r=0;r<a.length;r++)
        { for(int col=0;col<a[0].length;col++)
        {
            a[r][col]=scn.nextInt();
        }


        }
    }
    public static void display(int [][] b)
    { for(int r=0;r<b.length;r++)
    { for(int c=0;c<b[0].length;c++)
    {
        System.out.print(b[r][c]);
        System.out.print(" ");
    }

 System.out.println();

    }


    }
    public static  void sum(int [][] a,int[][] b)
{ for(int r=0;r<a.length;r++)
{
for(int c=0;c<a[0].length;c++)
{
a[r][c]+=b[r][c];

}

}
display(a);




}



}