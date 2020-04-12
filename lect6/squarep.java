import java.util.Scanner;
public class squarep{
public static Scanner scn=new Scanner(System.in);
public static void main(String[] arg)
{ int [][] a= new int [5][3];
input(a);
spirald(a);


}
public static void input(int [][] a)
{
    for(int r=0;r<a.length;r++)
    {
        for(int c=0;c<a[0].length;c++)
        {
            a[r][c]=scn.nextInt();
        }
    }
}
public static void display(int[][] a)
{ for(int r=0;r<a.length;r++)
{
    for(int c=0;c<a[0].length;c++)
    {
        System.out.print(a[r][c]);
       System.out.print(""); 
    }
}
System.out.println();
}
public static void spirald(int[][] a)
{ int rmin=0;
  int cmin=0;
  int cmax=a[0].length-1;
  int rmax=a.length-1;
  int tne=a.length*a[0].length;
   while(tne>0)
  {
      for(int i=cmin;i<=cmax && tne>0 ;i++)
  { System.out.print(a[rmin][i] + " ");
    tne--;
  }
  System.out.println();
  rmin++;

  for(int i=rmin;i<=rmax && tne>0 ;i++)
  {
      System.out.print(a[i][cmax] +" ");
      tne--;
  }
  System.out.println();
  cmax--;
  for(int i=cmax;i>=cmin  && tne>0;i--)
   { System.out.print(a[rmax][i] + " ");
    tne--;
   }
   System.out.println();
   rmax--;
   for(int i=rmax;i>=rmin && tne>0;i--)
   {
       System.out.print(a[i][cmin] + " ");
       tne--;
   }
   System.out.println();
   cmin++;
  }

}
}