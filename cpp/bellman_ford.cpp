/*
    Given a weighted, directed and connected graph of V vertices and E edges, 
    Find the shortest distance of all the vertex's from the source vertex S.
    Note: The Graph doesn't contain any negative weight cycle.
    Link:https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU#

    Approach:
    1) This step initializes distances from the source to all vertices as infinite and distance 
    to the source itself as 0. Create an array dist[] of size |V| with all values as infinite except 
    dist[src] where src is source vertex.
    2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices 
    in given graph. 
        a) Do following for each edge u-v 
             If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
                dist[v] = dist[u] + weight of edge uv
    3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v 
            If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle” 

    - The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight 
      cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a 
      negative weight cycle
    - How does this work? Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a 
      bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. 
      Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the 
      outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in
      any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no negative 
      weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges 
      guarantees to give shortest path with at-most (i+1) edges 

*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int i = 1; i <= V-1; i++){
            for(auto vec : adj){
                int u = vec[0];
                int v = vec[1];
                int w = vec[2];
                
                int newDist = dist[u] + w;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                }
            }
        }
        
        // to detect negative cycle
        // relax one more time
        for(auto vec : adj){
                int u = vec[0];
                int v = vec[1];
                int w = vec[2];
                
                int newDist = dist[u] + w;
                if(newDist < dist[v]){
                    cout << "negative len cycle exist" << endl;
                }
            }
        return dist;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends