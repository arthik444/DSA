int in[10001];
	vector<int>v;
	void khan(int n,vector<int> adj[]){
	    queue<int>q;
	    for(int i=0;i<n;i++){
	        if(in[i]==0) q.push(i);
	    }
	    while(!q.empty()){
	        int c=q.front();
	        q.pop();
	        v.push_back(c);
	        for(auto node:adj[c]){
	            in[node]--;
	            if(in[node]==0) q.push(node);
	        }
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    memset(in,0,sizeof(in));
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            in[adj[i][j]]++;
	        }
	    }
	    khan(V,adj);
	    return v;
	}