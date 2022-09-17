import java.util.ArrayList;
import java.util.PriorityQueue;

class Pair implements Comparable<Pair>{
    int parent,ver,wt;
    Pair(int parent,int ver,int wt){
        this.parent=parent;
        this.ver=ver;
        this.wt=wt;
    }

    @Override
    public int compareTo(Pair before) {
        return this.wt-before.wt;
    }
}

public class PrimsAlgo {
    static void addEdge(ArrayList<ArrayList<ArrayList<Integer>>> adj,int u, int v, int w){
        ArrayList<Integer> E1=new ArrayList<>();
        E1.add(u);
        E1.add(w);
        adj.get(v).add(E1);
        ArrayList<Integer> E2=new ArrayList<>();
        E2.add(v);
        E2.add(w);
        adj.get(u).add(E2);
    }

    static void spanningTree(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj)
    {
        boolean visited[]=new boolean[V];
        PriorityQueue<Pair> queue=new PriorityQueue<Pair>(); //will add the vertex in queue maintaining min heap property
        queue.add(new Pair(0,0,0));
        int ans=0;
        System.out.println("P  "+"V   "+"W");
        while (!queue.isEmpty()){
            Pair curr=queue.remove();  // will return the top(smallest) pair
            int v=curr.ver;
            if(!visited[v]){ //then we will have to add the neighbouring vertices of the vertex
                ans+=curr.wt;
                System.out.println(curr.parent+"  "+curr.ver+"   "+curr.wt);
                ArrayList<ArrayList<Integer>> neighbours=adj.get(v); //getting all the edges passing from vertex 'v'
                int vertex,weight;
                for(ArrayList<Integer> list:neighbours){
                    vertex=list.get(0);
                    weight=list.get(1);
                    if(!visited[vertex])
                        queue.add(new Pair(v,vertex,weight));
                }
                visited[v]=true;
            }
        }

        System.out.println("The total weight of Spanning Tree is "+ans);
    }

    public static void main(String[] args) {
        ArrayList<ArrayList<ArrayList<Integer>>> adj= new  ArrayList<ArrayList<ArrayList<Integer>>> (); //creating a graph using adjacency list
        int V=3;
        for (int i=0;i<V;i++){
            adj.add(new ArrayList<ArrayList<Integer>>());
        }
        addEdge(adj,0,1,5);
        addEdge(adj,0,2,1);
        addEdge(adj,2,1,3);
//        System.out.println(adj.get(1));
        
//        GFG ARTICLE TESTCASE
//        addEdge(adj, 0, 1, 4);
//        addEdge(adj, 0, 7, 8);
//        addEdge(adj, 1, 2, 8);
//        addEdge(adj, 1, 7, 11);
//        addEdge(adj, 2, 3, 7);
//        addEdge(adj, 2, 8, 2);
//        addEdge(adj, 2, 5, 4);
//        addEdge(adj, 3, 4, 9);
//        addEdge(adj, 3, 5, 14);
//        addEdge(adj, 4, 5, 10);
//        addEdge(adj, 5, 6, 2);
//        addEdge(adj, 6, 7, 1);
//        addEdge(adj, 6, 8, 6);
//        addEdge(adj, 7, 8, 7);
        spanningTree(V,adj);
    }
}
