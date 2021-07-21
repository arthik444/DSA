void DFS(int curr,vector<vector<int>> &adj,vector<pi> & Time,int *time){
	Time[curr].first = (*time)++;
 
	for(auto ele : adj[curr]){
		DFS(ele,adj,Time,time);
	}
	Time[curr].second = (*time)++;
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n,a,b;
	cin>>n;
	vector<pi> Time(n+1);
	vector<vector<int>> adj(n+1,vector<int>());
	for(int i=1;i<n;i++){
		cin>>a>>b;
		adj[a].push_back(b);
	}
	int time=0;
	DFS(1,adj,Time,&time);
	int q,c;
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>a>>b>>c;
		if(a==0){  // b ,c
			if(Time[b].first < Time[c].first && Time[b].second > Time[c].second ){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}else{
			if(Time[c].first < Time[b].first && Time[c].second > Time[b].second ){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}
	}
 
}