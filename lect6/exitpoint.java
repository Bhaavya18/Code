import java.util.Scanner;
public class exitpoint{
public static Scanner scn= new Scanner(System.in);
public static void main(String[] arg)
{
    int [][]a=new int[5][5];
    input(a);
    exitpoint(a);

}
public static void input(int [][] a)
{ for(int r=0;r<a.length;r++)
{ 
    for(int c=0;c<a[0].length;c++)
{
    a[r][c]=scn.nextInt();
    // System.out.print("");
}
// System.out.println();

}


}
public static void exitpoint(int [][] a)
{ int dir=0;
int r=0;
int c=0;
while(true)
{ dir=(dir+a[r][c])%4;
    if(dir==0)
    {
        c++;
        if(c==a[0].length)
        {
            System.out.print(r+","+(c-1));
            break;
        }
    }
    else if(dir==1)
    {
     r++;
     if(r==a.length)
     {System.out.print((r-1)+","+c);
     break;}

    }
    else if(dir==2)
    { c--;
        if(c==-1)
        {
            System.out.print(r+","+(c+1));
            break;
        }
    }
    else if(dir==3)
    {
        r--;
        if(r==-1)
        {
            System.out.print((r+1)+","+c);
            break;
        }
    }
}



}



}




