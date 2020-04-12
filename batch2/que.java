public class que
{
    int [] que;
    int size=0;
    int head=0;
    int tail=-1;
    que()
    {
        int [] que=new int[10];
    }
    que(int size)
    {
        this.que=new  int[size];
    }
    public boolean isempty()
    {
        return this.size==0;
    }
    public void push(int data)
    {
        if(this.size==que.length)
        {
            System.out.print("que is full");
            return;
        }
        this.tail=(this.tail+1)%this.que.length;
        que[this.tail]=data;
        this.size++;

    }
    public int front()
    {
        if(this.size==0)
        return -1;

        return this.que[this.head];
    }

    public int pop()
    {
        if(this.size==0)
        {
            System.out.print("que is empty");
            return -1;
        }
        int rv=que[this.head];
        que[this.head]=0;
        this.size--;
        this.head=(this.head+1)%this.que.length;
        return rv;
    }

    public void display()
    {
        for(int i=0;i<this.size;i++)
        {
            int val=this.que[(this.head+i)%this.que.length];
            System.out.println(val+" ");
        }
        System.out.println();
    }

}