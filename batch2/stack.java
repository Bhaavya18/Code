public class stack{
int [] st;
int tos=-1;

 stack(){
  this.st=new int[10];
}
 stack(int size)
{
    this.st=new int[size];
}
 stack(int [] arr)
{
    this.st=new int[2*arr.length];
    for(int i=0;i<arr.length;i++)
    {
        st[i]=arr[i];
    }
}

public  void push(int data)
{
    if(tos+1==st.length)
    {
        System.out.print("stack overflow"+tos);
        return;
    }

    st[++tos]=data;
}

public  int top()
{
    if(tos==-1)
    return -1;

    return st[tos];
}

public int pop()
{
    if(tos==-1)
    {
        System.out.print("stack is empty");
        return -1;
    }

    int rv=st[tos];      //return st[tos--];
    st[tos]=0;
    return rv;
}

public  int size()
{
    return tos+1;
}

public  boolean isempty()
{
    if(tos==-1)
    return true;

    return false;
}

}
