public class FloydWarshall {
        public void shortest_distance(int[][] matrix) {
            int max = 10000000; // A value to represent infinity or unreachable distance
            int V = matrix.length; // Number of vertices in the graph

            // Convert all -1 values in the matrix to max (representing infinity)
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (matrix[i][j] == -1) {
                        matrix[i][j] = max;
                    }
                }
            }

            // Apply Floyd-Warshall algorithm to find the shortest distances between all pairs of vertices
            for (int k = 0; k < V; k++) {
                for (int i = 0; i < V; i++) {
                    for (int j = 0; j < V; j++) {
                        if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
                            // If a shorter path is found through vertex k, update the distance matrix
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
                        }
                    }
                }
            }

            // Convert all max values back to -1 in the matrix
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (matrix[i][j] == max) {
                        matrix[i][j] = -1;
                    }
                }
            }
        }
}
