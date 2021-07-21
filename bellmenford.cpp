int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	   int parent[n];
	   vector<int> value(n,INT_MAX);
	   parent[0]=-1;
	   value[0]=0;
	   bool updated;
	   for(int i=0;i<n-1;i++){
	       updated=false;
	       for(int j=0;j<edges.size();j++){
	           int u=edges[j][0];
	           int v=edges[j][1];
	           int wt=edges[j][2];
	           if(value[u]!=INT_MAX && value[u]+wt<value[v]){
	               value[v]=wt+value[u];
	               parent[v]=u;
	               updated=true;
	           }
	       }
	       if(updated==false) break;
	   }
	   if(updated==false){
	       return 0;
	   }else{
	       for(int j=0;j<edges.size();j++){
	           int u=edges[j][0];
	           int v=edges[j][1];
	           int wt=edges[j][2];
	           if(value[u]!=INT_MAX && value[u]+wt<value[v]){
	               return 1;
	           }
	       }
	       return 0;
	   }
	}