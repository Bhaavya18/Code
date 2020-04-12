import java.util.Scanner;
public class output
{
public static Scanner scn=new Scanner(System.in);
public static void main(String[] argv)
{ System.out.print("enter n");
int n=scn.nextInt();
int c=call(n);
System.out.print(c);

}
public static int  call(int n)
{
    if(n<=1)
    {
        System.out.println("base"+ n);
        return n+1;
    }
    int count=0;
    System.out.println("pre:"+n);
    count+=call(n-1);
    System.out.println("In"+n);
    count=count+call(n-2);
    System.out.println("post"+n);
    return count+3;
}





}