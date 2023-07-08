/*
    Given a graph and a source vertex in graph, find shortest paths from source to all vertices in the given graph.
    Link: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

    Approach: Greedy
    - For Dijkstra’s algorithm, it is always recommended to use heap (or priority queue) as the required 
     operations (extract minimum and decrease key) match with speciality of heap (or priority queue). However,
     the problem is, priority_queue doesn’t support decrease key. To resolve this problem, do not update a key, 
     but insert one more copy of it. So we allow multiple instances of same vertex in priority queue. 
     This approach doesn’t require decrease key operation and has below important properties.

    - Whenever distance of a vertex is reduced, we add one more instance of vertex in priority_queue.
      Even if there are multiple instances, we only consider the instance with minimum distance and ignore 
      other instances.
      The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue 
      and O(Log E) is same as O(Log V)

      Algo:
        1) Initialize distances of all vertices as infinite.

        2) Create an empty priority_queue pq.  Every item
        of pq is a pair (weight, vertex). Weight (or 
        distance) is used used as first item  of pair
        as first item is by default used to compare
        two pairs

        3) Insert source vertex into pq and make its
        distance as 0.

        4) While either pq doesn't become empty
            a) Extract minimum distance vertex from pq. 
            Let the extracted vertex be u.
            b) Loop through all adjacent of u and do 
            following for every vertex v.

                // If there is a shorter path to v
                // through u. 
                If dist[v] > dist[u] + weight(u, v)

                    (i) Update distance of v, i.e., do
                            dist[v] = dist[u] + weight(u, v)
                    (ii) Insert v into the pq (Even if v is
                            already there)
                    
        5) Print distance array dist[] to print all shortest
        paths. 
*/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        
        queue<pair<int, int>> pq; // <dist, node>
        pq.push({0, S});
        while(!pq.empty()){
            int node = pq.front().second;
            int d = pq.front().first;
            pq.pop();
            
            for(vector<int>& v : adj[node]){
                int nbr = v[0];
                int edgeWt = v[1];
                int newDist = d + edgeWt;
                
                if(dist[nbr] > newDist){
                    dist[nbr] = newDist;
                    pq.push({newDist, nbr});
                }
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends