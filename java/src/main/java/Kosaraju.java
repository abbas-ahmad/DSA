import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
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

    public static void main(String args[]) throws IOException {

        BufferedReader read =
                new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String str[] = read.readLine().trim().split(" ");
            int V = Integer.parseInt(str[0]);
            int E = Integer.parseInt(str[1]);

            ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<ArrayList<ArrayList<Integer>>>();
            for(int i=0;i<V;i++)
            {
                adj.add(new ArrayList<ArrayList<Integer>>());
            }

            int i=0;
            while (i++<E) {
                String S[] = read.readLine().trim().split(" ");
                int u = Integer.parseInt(S[0]);
                int v = Integer.parseInt(S[1]);
                int w = Integer.parseInt(S[2]);
                ArrayList<Integer> t1 = new ArrayList<Integer>();
                ArrayList<Integer> t2 = new ArrayList<Integer>();
                t1.add(v);
                t1.add(w);
                t2.add(u);
                t2.add(w);
                adj.get(u).add(t1);
                adj.get(v).add(t2);
            }

            int S = Integer.parseInt(read.readLine());

            Solution ob = new Solution();

            int[] ptr = ob.dijkstra(V, adj, S);

            for(i=0; i<V; i++)
                System.out.print(ptr[i] + " ");
            System.out.println();
        }
    }
}
}