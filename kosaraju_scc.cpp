	int vis[5001];
	vector<int>order;
	void dfs(int x,vector<int> adj[]){
	    vis[x]=1;
	    for(auto c:adj[x]){
	        if(vis[c]==0) dfs(c,adj);
	    }
	    order.push_back(x);
	}
	void dfs1(int x,vector<int> tr[]){
	    vis[x]=1;
	    for(auto c:tr[x]){
	        if(vis[c]==0) dfs1(c,tr);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        int c=0;
        vector<int>tr[V];
       memset(vis,0,sizeof(vis));
       for(int i=0;i<V;i++){
           for(int j=0;j<adj[i].size();j++){
               tr[adj[i][j]].push_back(i);
           }
       }
       for(int i=0;i<V;i++){
           if(vis[i]==0) dfs(i,adj);
       }
       memset(vis,0,sizeof(vis));
       for(int i=0;i<V;i++){
           if(vis[order[V-i-1]]==0){
               dfs1(order[V-i-1],tr);
               c++;
           }
       }
       return c;
    }