import java.util.Scanner;
public class numpattern{
 public static Scanner scn= new Scanner (System.in);
public static void main(String[] args)
{ int n=scn.nextInt();
numdiamond(n);
}
public static void numdiamond(int n)
{int nsp=n/2;
int nst=1;
int r;
for(r=1;r<=n;r++)
{
    for(int csp=1;csp<=nsp;csp++)
    {
        System.out.print(" ");
    }
    int val=r;
    if(val>(n/2)+1)
    { val=n-r +1;

    }
    for(int cst=1;cst<=nst;cst++)
    { System.out.print(val);
    if(cst<=nst/2)
    { val++;}
    else
    { val--;}
    }
    if(r<=n/2)
    {nst = nst+2;
    nsp--;
    }
    else{
        nst-=2;
        nsp++;
    }
    System.out.println();
}
}
    
    }

