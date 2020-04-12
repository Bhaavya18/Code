import java.util.Scanner;
public class bs{
 public static Scanner scn=new Scanner(System.in);   
 public static int bss(int [] a,int data,int si,int ei)
 {
     while(si<=ei)
     {
         int mid=(si+ei)/2;
         if(a[mid]==data)
         return mid;
         else if(a[mid]>data)
         ei=mid-1;
         else
         si=mid+1;
     }return -1;
 } 
 public static int upperbound(int [] a,int data)
 {
     int si=0;
     int ei=a.length-1;
     while(si<=ei)
 {
     int mid=(si+ei)/2;
     if(a[mid]==data)
     {
         if(mid+1<a.length && a[mid]==a[mid+1])
         {
          si=mid+1;
         }
         else
        return  mid;
     }
     else if(a[mid]>data)
     {
         ei=mid-1;
     }
     else
     si=mid-1;
 }return -1;
 } 
 public static int lowerbound(int [] a,int data)
 {
     int si=0;
     int ei=a.length-1;
     while(si<=ei)
     {
         int mid=(si+ei)/2;
         if(a[mid]==data)
         {
             if(mid-1>=0 && a[mid]==a[mid-1])
             {
                 ei=mid-1;
             }
             else
             return mid;
         }
         else if(a[mid]>data)
         {
             ei=mid-1;
         }
         else
         si=mid+1;
     }return -1;
 }
 public static int nearest(int [] a,int data)
 {
     int si=0;
     int ei=a.length-1;
     if(a[si]>data)
     {
      return si;
     }
     if(data>a[ei])
     {return ei;
     }
     while(si<=ei)
     {
         int mid=(si+ei)/2;
         if(a[mid]==data)
         return mid;
         else if(a[mid]>data)
         ei=mid-1;
         else
         si=mid+1;
     }
     if(data-a[ei]>a[si]-data)
     { 
         return si;
     }
     else 
     return ei;
 }
 public static int rotsearch(int [] a,int data)
 {
     int si=0;
     int ei=a.length-1;
     int c;
     while(si==ei)
     {
        int  mid=(si+ei)/2;
         if(a[mid]-a[si]<0 && a[ei]-a[mid]>0)
         ei=mid+1;
         else
         si=mid-1;

     }
     if(si==0)
     {
         if(a[si]==data)
         return si;
         else
        c= bss(a,data,si+1,a.length-1);
     }
     else
     {
        c= bss(a,data,0,si-1);
        if(c==-1)
        c=bss(a,data,si+1,a.length-1);
        
     }
     return c;
     
 }
 public static void targetsum(int [] a,int data)
 {
     int si=0;
     int ei=a.length-1;
     while(si<=ei)
     {
         if(a[si]+a[ei]==data)
         {
             System.out.print(a[si]+ ","+a[ei]+" ");
             si++;
             ei--;
         }
         else if(a[si]+a[ei]>data)
         {
             ei--;
         }
         else
         si++;
     }
 }
 //public static void triplet(int [] a,int data)
 //{
  //  int k=0;
  //  int si=k+1;
   // ei=a.length-1;
   // while(si<=ei)
    //{
       // if((a[si]+a[ei]+a[k])==data)
       // {
        //    System.out.print(a[si]+" ,"+a[ei]+","+a[k]+","+" ");
            
       // }
  //  }
 //}
 public static void main(String[] arg)
 {
    // int [] a={1,2,3,4,5,0};
    int [] a={-1,1,3,5,7,9};
     int data=scn.nextInt();
     //System.out.print(bss(a,data,0,a.length-1));
     //System.out.print(upperbound(a,data));
    // System.out.print(lowerbound(a,data));
   // System.out.print(nearest(a,data));
  // System.out.print(rotsearch(a,data));
  targetsum(a,data);
 } 
}