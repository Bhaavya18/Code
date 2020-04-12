import java.util.Scanner;
public class find{
public static Scanner scn=new Scanner(System.in);
public static void main(String[] args)
{ int[] arr= new int[]{2,5,5,3,8,9,10};
    int ele=scn.nextInt();
 boolean ex=find2(arr,ele);
 System.out.println(ex);

} 
public static boolean find2(int [] a, int ele)
{ for(int i=0;i<a.length;i++)
{
    if(ele==a[i])
    {
        return true;
    }
}

return false;`

}   


}