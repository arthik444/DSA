 int vis[100001],in[100001],low[100001];
    int t=0,b=0;
    void dfs(int node,int par,vector<int> v[]){
        vis[node]=1;
        in[node]=low[node]=t++;
        for(auto child:v[node]){
            if(child==par) continue;
            if(vis[child]==1){
                low[node]=min(low[node],in[child]);
                b++;
            }else{
                dfs(child,node,v);
                low[node]=min(low[node],low[child]);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int c=0;
        vector<int> v[n];
        for(int i=0;i<connections.size();i++){
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(connections[i][0]);
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfs(i,-1,v);
                c++;
            }
        }
        if(c==1) return 0;
        if(b>=c) return c-1;
        else return -1;
    }