public class client
{    
               
    public static void main(String [] args)
    {
        //stack st=new stack(5);
       /* st.push(5);
        System.out.println(st.pop());
        //System.out.print(st.top());
        System.out.print(st.top());*/
       // que qu=new que(5);
      /*  qu.push(10);
        qu.push(20);
        qu.push(30);
        qu.push(40);
        qu.push(50);
        qu.display();
        qu.pop();
        qu.pop();
        qu.pop();
        System.out.print(qu.front()); */
        /*dynamicstack st1=new dynamicstack(2);
        st1.push(10);
        st1.push(20);
        st1.push(40);
        System.out.print(st1.top()); */

        //int [] arr={4,5,2,25};
        que qu=new que(4);
        qu.push(4);
        qu.push(5);
        qu.push(2);
        qu.push(25);
        rightmost(qu);
    }
}