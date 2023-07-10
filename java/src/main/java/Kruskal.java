import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Kruskal {

    static int[] parent;

    static int find(int a){
        if(parent[a] == a) return a;
        return find(parent[a]);
    }

    static void union(int a, int b){
        int aRoot = find(a);
        int bRoot = find(b);

        if(aRoot == bRoot) return;
        parent[bRoot] = aRoot;
    }

    public int findMSTCost(int V, List<Edge> edgeList){
        Collections.sort(edgeList);
        int mst = 0;

        parent = new int[V];
        for(int i = 0; i < V; i++){
            parent[i] = i;
        }
        int count = 0;
        for(Edge edge : edgeList){
            int sRoot = find(edge.src);
            int dRoot = find(edge.dest);

            if(sRoot != dRoot){
                union(sRoot, dRoot);
                count++;
                mst += edge.weight;
            }
        }
        return mst;
    }
}

class Edge implements Comparable<Edge>{
    int src;
    int dest;
    int weight;

    public Edge(int src, int dest, int weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    @Override
    public int compareTo(Edge e) {
        return this.weight - e.weight;
    }
}