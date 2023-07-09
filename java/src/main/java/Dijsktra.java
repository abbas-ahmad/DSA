import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

/*
* For Dijkstra's algorithm, it is always recommended to use heap (or priority queue) as the required operations
* (extract minimum and decrease key) match with the specialty of the heap (or priority queue). However, the problem is,
* that priority_queue doesn't support the decrease key.
* To resolve this problem, do not update a key, but insert one more copy of it. So we allow multiple instances of the
* same vertex in the priority queue. This approach doesn't require decreasing key operations and has below important properties.
*
* Whenever the distance of a vertex is reduced, we add one more instance of a vertex in priority_queue. Even if there are multiple
* instances, we only consider the instance with minimum distance and ignore other instances.
* The time complexity remains O(ELogE)) as there will be at most O(E) vertices in the priority queue
* and for sparse graph O(Log E) is the same as O(Log V).
* */
public class Dijsktra {
        static int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int S) {
            // Priority queue to store nodes with their distances
            PriorityQueue<Pair> pq = new PriorityQueue<>((p1, p2) -> Integer.compare(p1.dist, p2.dist));

            // Array to store the shortest distances from the source vertex
            int[] ans = new int[V];

            // Array to track visited nodes
            boolean[] vis = new boolean[V];

            // Initializing the ans array with maximum values
            Arrays.fill(ans, Integer.MAX_VALUE);
            ans[S] = 0;

            pq.offer(new Pair(S, 0));
            vis[S] = true;

            while (!pq.isEmpty()) {
                // Extracting the node with the minimum distance from the priority queue
                Pair top = pq.poll();
                int v = top.node;
                int dist = top.dist;

                // Marking the current node as visited
                vis[v] = true;

                // Iterating over the neighbors of the current node
                for (ArrayList<Integer> edge : adj.get(v)) {
                    int nbr = edge.get(0);
                    int weight = edge.get(1);

                    // If the neighbor has not been visited and a shorter path is found
                    if (!vis[nbr]) {
                        if (ans[nbr] > dist + weight) {
                            // Updating the distance and adding the neighbor to the priority queue
                            ans[nbr] = dist + weight;
                            pq.offer(new Pair(nbr, ans[nbr]));
                        }
                    }
                }
            }

            return ans;
        }
    }

    class Pair {
        int node;
        int dist;

        Pair(int n, int d) {
            node = n;
            dist = d;
        }
    }

