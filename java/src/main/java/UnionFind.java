public class UnionFind {
    int[] parent;
    int[] rank;
    UnionFind(int n){
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    public int find(int a){
        if(parent[a] == a) return a;
        return find(parent[a]);
    }

    public int findWithPathCompression(int a){
        if(parent[a] != a){
            parent[a] = findWithPathCompression(parent[a]);
        }
        return parent[a];
    }

    public void union(int a, int b){
        int aRoot = find(a);
        int bRoot = find(b);

        if(aRoot == bRoot) return;

        parent[bRoot] = aRoot;
    }

    public void unionByRank(int a, int b){
        int aRoot = find(a);
        int bRoot = find(b);

        if(aRoot == bRoot) return;

        if(rank[aRoot] > rank[bRoot]){
            parent[bRoot] = aRoot;
        }
        else if (rank[aRoot] < rank[bRoot]) {
            parent[aRoot] = bRoot;
        }
        else{
            // either aRoot or bRoot can we parent
            parent[bRoot] = aRoot;
            rank[aRoot]++;
        }
    }
}
