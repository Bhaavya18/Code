import java.util.ArrayList;
public class graph1
{

    public static class Edge{
        int v=0;
        int w=0;
        Edge(final int v, final int w) {
            this.v = v;
            this.w = w;

        }
    }

    public static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();

    public static void addedge( int u,  int v, int w) {
        if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size())
            return;
        graph.get(u).add(new Edge(v, w));
        graph.get(v).add(new Edge(u, w));

    }

    public static void constructg() {
        for (int i = 0; i < 7; i++) {
            graph.add(new ArrayList<>());

        }
        addedge(0, 3, 10);
        addedge(0, 1, 10);
        addedge(1, 2, 10);
        addedge(2, 3, 40);
        addedge(3, 4, 10);
        addedge(4, 5, 2);
        addedge(4, 6, 8);
        addedge(5, 6, 2);
        // display();
    }

    public static void removeedge(final int u, final int v, final int w) {
         ArrayList<Edge> list = graph.get(u);
        int i = 0;
        while (i < list.size()) {
             Edge e = list.get(i);
            if (e.v == v && e.w == w)
                break;
            i++;
        }
        list.remove(i);
        int j = 0;
         ArrayList<Edge> list2 = graph.get(v); // first all in 2d matrix 0f we are going to specific u then we are
                                                    // accessing the array
        // present at that particular index
        while (j < list2.size()) {
             Edge e = list2.get(j);
            if (e.v == u && e.w == w)
                break;
            j++;
        }
        list2.remove(j);

    }

   public static  void removevertex(final int u) {
         ArrayList<Edge> list = graph.get(u);
        int i = list.size() - 1;
        while (i>=0) {
             Edge e = list.get(i);
            removeedge(u, e.v, e.w);
            i--;
        }
    }

    public static void display() {
        for (int i = 0; i < graph.size(); i++) {
            System.out.print(i + "->");
            for ( Edge e : graph.get(i)) {
                System.out.print("(" + e.v + ", " + e.w + ")" + " ");
            }
            System.out.println();
        }

    }

    public static void main(final String[] args)
    {
        constructg();
       // removeedge(3,4,10);
       removevertex(3);
        display();


        

    }
}