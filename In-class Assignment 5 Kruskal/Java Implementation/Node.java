import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Node{
    private int source;
    private int dest;
    private int weight;

    public Node(int source, int dest, int weight) {
        this.source = source;
        this.dest = dest;
        this.weight = weight;
    }
    public int getWeight() {
        return weight;
    }

    /*
    *
    *   Sorting Algorithm
    *
     */
    public static Comparator<Node> asc = new Comparator<Node>() {
        @Override
        public int compare(Node o1, Node o2) {
            int num1 = o1.getWeight();
            int num2 = o2.getWeight();
            return (num1-num2);
        }
    };
    @Override
    public String toString(){
        return source+" "+ dest+" "+weight;
    }

    /*
    *
    *   Parent Tracker
    *
     */
    static int getParent(int v, int tracker[]){
        if(tracker[v] == v){
            return v;
        }
        return getParent(tracker[v],tracker);
    }

    /*
    *
    *   Kruskal Method
    *
     */
    static void kruskal(int[][] a,int V, int E){
        int edgeCount = 0;
        int [][] b = new int[V-1][3];
        int tracker[] = new int[V];
        for(int i = 0;i<V;i++){
            tracker[i] = i;
        }
        int count = 0;
        int i2 = 0;
        while (count < V-1){
            int source = getParent(a[i2][0],tracker);
            int destination = getParent(a[i2][1],tracker);
            if(source!=destination){
                b[count][0] = a[i2][0];
                b[count][1] = a[i2][1];
                b[count][2] = a[i2][2];
                edgeCount = edgeCount+b[count][2];
                System.out.println(b[count][0]+" "+b[count][1]);
                count++;
                tracker[destination] = source;
            }
            i2++;
        }
        System.out.println("Sum of Edge Weight: "+edgeCount);
    }


    /*
    *
    *   Driver Method
    *
     */
    public static void main(String[] args) throws IOException {
        int V = 9, E = 14;
        int edges[][] = {
            {0, 1, 10},
            {0, 2, 12},
            {1, 2, 9},
            {1, 3, 8},
            {2, 4, 4},
            {2, 5, 1},
            {3, 4, 7},
            {3, 6, 8},
            {3, 7, 5},
            {4, 5, 3},
            {5, 7, 6},
            {6, 7, 9},
            {6, 8, 2},
            {7, 8, 11}
        };
        ArrayList<Node> x = new ArrayList<Node>();
        for (int i = 0;i<E;i++){
            x.add(new Node(edges[i][0],edges[i][1],edges[i][2]));
        }
        Collections.sort(x,Node.asc);
        PrintWriter p = new PrintWriter(new FileWriter("ArrayList.txt"));
        for (Node a:x) {
            p.println(a);
        }
        p.close();
        int new_array[][] = new int[E][3];
        BufferedReader b = new BufferedReader(new FileReader("ArrayList.txt"));
        String line;
        int i = 0;
        while ((line = b.readLine())!=null){
            String[] arrOfString = line.split(" ");
            int x1 = Integer.parseInt(arrOfString[0]);
            int x2 = Integer.parseInt(arrOfString[1]);
            int x3 = Integer.parseInt(arrOfString[2]);
            new_array[i][0] = x1;
            new_array[i][1] = x2;
            new_array[i][2] = x3;
            i++;
        }
        b.close();
        kruskal(new_array,V,E);
    }
}