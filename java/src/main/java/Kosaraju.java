import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

class Kosaraju {
    public int kosaraju(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] vis = new boolean[V];
        Stack<Integer> s = new Stack<>();

        // First DFS traversal to find topo sorting
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, s);
            }
        }

        // Transpose the graph
        ArrayList<ArrayList<Integer>> gdash = new ArrayList<>();
        for (int i = 0; i < V; i++) gdash.add(new ArrayList<>());

        for (int i = 0; i < V; i++) {
            for (int nbr : adj.get(i)) {
                gdash.get(nbr).add(i);
            }
        }

        Arrays.fill(vis, false);
        int scc = 0;

        // Second DFS traversal on the transpose graph
        while (!s.isEmpty()) {
            int node = s.pop();
            if (!vis[node]) {
                dfs(node, gdash, vis, s);
                scc++;
            }
        }

        return scc;
    }

    private void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] vis, Stack<Integer> s) {
        vis[node] = true;

        for (int nbr : adj.get(node)) {
            if (!vis[nbr]) {
                dfs(nbr, adj, vis, s);
            }
        }

        s.push(node);
    }

    public static void main (String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0)
        {
            // arraylist of arraylist to represent graph
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

            int V = Integer.parseInt(sc.next());
            int E = Integer.parseInt(sc.next());

            for(int i =0; i < V; i++)
                adj.add(i, new ArrayList<Integer>());

            for(int i = 1; i <= E; i++)
            {    int u = Integer.parseInt(sc.next());
                int v = Integer.parseInt(sc.next());

                // adding directed edgese between
                // vertex 'u' and 'v'
                adj.get(u).add(v);
            }

            Kosaraju ob = new Kosaraju();
            System.out.println(ob.kosaraju(V, adj));
        }
    }
}