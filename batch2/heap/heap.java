import java.util.ArrayList;
public class heap{

private ArrayList<Integer>arr;

private  boolean ismax=false;

public void createheap(int [] ar)   //heap created by downheapify has complexity nlogn whereas he
{
    this.arr=new ArrayList<>();
    for(int ele:ar)
    {
       this.arr.add(ele);
    }

    for(int i=arr.size()-1;i>=0;i--)
    {
        downheapify(i);
    }
}

public heap(boolean ismax,int [] arr)
{
    this.ismax=ismax;
    createheap(arr);
}

public void swap(int i,int j)
{
    int val1=arr.get(i);
    int val2=arr.get(j);
     
     arr.set(i,val2);
     arr.set(j,val1);
}

public void downheapify(int idx)
{
    int maxidx=idx;      //we are assuming maximum to be present at zero index ie at root
    int lci=2*idx +1;
    int rci=2*idx +2;

    if(lci<arr.size() && compareto(lci,maxidx)>0)
    {
        maxidx=lci;
    }

    if(rci<arr.size() && compareto(rci,maxidx)>0)
    maxidx=rci;

    if(maxidx!=idx)       //if  parent does not contain maximum value then swap;
    {
        swap(maxidx,idx);

        downheapify(maxidx);
    }
}

public void upheapify(int cidx)   //
{
    int pidx=(cidx-1)/2;

    if(pidx >=0 && compareto(cidx,pidx)>0)
    {
        swap(cidx,pidx);
        upheapify(pidx);
    }

}

public void push(int ele)     //o(n)
{
    arr.add(ele);
    
    upheapify(arr.indexOf(ele));

}

public void pop()
{

    swap(0,arr.size()-1);
    
    arr.remove(arr.get(arr.size()-1));

    downheapify(0);
}

public void update(int idx,int ele)
{
    arr.set(idx,ele);   //first set that index which is updated then sort the heap
    upheapify(idx);
    downheapify(idx);
}


public int top()
{
    if(arr.size()==0)
    return -1;


    return arr.get(0);
}

public void display()
{
    for(int i=0;i<arr.size();i++)
    {
        System.out.print(arr.get(i)+" ");
    }
}

public int compareto(int cidx,int pidx)
{
    if(ismax)
    {
        return arr.get(cidx)-arr.get(pidx);
    }

    else
    {
        return arr.get(pidx)-arr.get(cidx);

    }
}


}