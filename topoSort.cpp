void dfs(int cur, vector<int> adj[], vector<bool>& vis, stack<int>& s){
        vis[cur] = true;
        
        for(int nbr : adj[cur]){
            if(!vis[nbr]){
                dfs(nbr, adj, vis, s);
            }
        }
        s.push(cur);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    stack<int> s;
	    vector<bool> vis(V, false);
	    
	    for(int i = 0; i < V; i++){
	        if(!vis[i]){
	            dfs(i, adj, vis, s);
	        }
	    }
	    vector<int> res;
	    while(!s.empty()){
	        res.push_back(s.top());
	        s.pop();
	    }
	    return res;
	}