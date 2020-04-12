public class dynamicstack extends stack{

dynamicstack()
{
    super();
}
dynamicstack(int size)
{
    super(size);
}
dynamicstack(int [] arr)
{
    super(arr);
}
@Override
public void push(int data)
{
    if(this.tos+1==st.length)
    {
        int[] temp=st;
        st=new int[2*temp.length];
        for(int i=0;i<temp.length;i++)
        {
            st[i]=temp[i];
        }
    }
    super.push(data);
}


}