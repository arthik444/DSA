int vis[100001];
    int col[100001];
    bool flag=true;
    bool dfs(int a,int c,vector<int>adj[]){
        vis[a]=1;
        col[a]=c;
        for(auto ch:adj[a]){
            if(vis[ch]==0){
                if(dfs(ch,c^1,adj)==false) return false;
            }else{
                if(col[ch]==col[a]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    memset(vis,0,sizeof(vis));
	    for(int i=0;i<V;i++){
	        if(vis[i]==0) flag=(flag && dfs(i,0,adj));
	    }
	    return flag;
	}
