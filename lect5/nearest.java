import java.util.Scanner ;
public class nearest
{ public static Scanner scn=new Scanner(System.in);
public static void main(String[] arg)
{ int []a=new int[7];
input(a);
System.out.println("enter data");
int data=scn.nextInt();
int c;
c=near2(a,data);
System.out.println(c);
}
public static void input(int[]a)
{
    for(int i=0;i<a.length;i++)
    { System.out.println("enter no");
    a[i]=scn.nextInt();
    }
}
public static int near2(int[]a,int data)
{ if(data<a[0])
return  a[0];
else if(data>a[a.length-1])
return a[a.length-1];
int si=0;
int ei=a.length-1;
while(si<=ei)
{ int mid=(si+ei)/2;
if(a[mid]==data)
return mid;
else if(data>a[mid])
si=mid+1;
else
ei=mid-1;
}
if(data-a[ei]<a[si]-data)
return a[ei];
else
return a[si];

}

}










