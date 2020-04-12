import java.util.Scanner;
public class allindex{
public static Scanner scn=new Scanner(System.in);
public static void main(String[] argv)
{
int [] a=new int{10,8,9,10,11,13,10,16,18,10,13};
System.out.print("enter data");
int data=scn.nextInt();


}
public static int [] allindex(int []a,int vidx,int data,int size)
{ if(vidx==a.length)
{ int [] basearr=new int[size];
return basearr;
}
if(a[vidx]==data)
size++;
int [] recans=allindex(a,vidx+1,data,size);
if(arr[vidx]==data)
{
    recans[size-1]=vidx;
    return recans;
}


}


}