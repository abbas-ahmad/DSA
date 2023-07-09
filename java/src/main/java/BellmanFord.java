import java.util.Arrays;

public class BellmanFord {
        public int isNegativeWeightCycle(int n, int[][] edges) {
            int[] dist = new int[n];
            Arrays.fill(dist, Integer.MAX_VALUE);
            dist[0] = 0;

            // Relax edges n-1 times
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < edges.length; j++) {
                    int u = edges[j][0];
                    int v = edges[j][1];
                    int w = edges[j][2];

                    if (dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            // Check for negative weight cycles
            for (int j = 0; j < edges.length; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];

                if (dist[u] != Integer.MAX_VALUE && dist[v] > dist[u] + w) {
                    return 1;
                }
            }

            return 0;
        }
}
